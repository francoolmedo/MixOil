#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/inicio_v2_.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/inicio_v2_.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=configuraciones.c main.c Memoria.c rutinas_genericas.c timer.c i2cEmem.c ctrl_param.c recepcion_serie.c parametrizacion.c pulso_watch.c APQ.c automatico.c manual.c quemador.c molino.c precalentador.c generar_palabra_A.c sonidosAlarma.c tiempo_Quemador.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/configuraciones.o ${OBJECTDIR}/main.o ${OBJECTDIR}/Memoria.o ${OBJECTDIR}/rutinas_genericas.o ${OBJECTDIR}/timer.o ${OBJECTDIR}/i2cEmem.o ${OBJECTDIR}/ctrl_param.o ${OBJECTDIR}/recepcion_serie.o ${OBJECTDIR}/parametrizacion.o ${OBJECTDIR}/pulso_watch.o ${OBJECTDIR}/APQ.o ${OBJECTDIR}/automatico.o ${OBJECTDIR}/manual.o ${OBJECTDIR}/quemador.o ${OBJECTDIR}/molino.o ${OBJECTDIR}/precalentador.o ${OBJECTDIR}/generar_palabra_A.o ${OBJECTDIR}/sonidosAlarma.o ${OBJECTDIR}/tiempo_Quemador.o
POSSIBLE_DEPFILES=${OBJECTDIR}/configuraciones.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/Memoria.o.d ${OBJECTDIR}/rutinas_genericas.o.d ${OBJECTDIR}/timer.o.d ${OBJECTDIR}/i2cEmem.o.d ${OBJECTDIR}/ctrl_param.o.d ${OBJECTDIR}/recepcion_serie.o.d ${OBJECTDIR}/parametrizacion.o.d ${OBJECTDIR}/pulso_watch.o.d ${OBJECTDIR}/APQ.o.d ${OBJECTDIR}/automatico.o.d ${OBJECTDIR}/manual.o.d ${OBJECTDIR}/quemador.o.d ${OBJECTDIR}/molino.o.d ${OBJECTDIR}/precalentador.o.d ${OBJECTDIR}/generar_palabra_A.o.d ${OBJECTDIR}/sonidosAlarma.o.d ${OBJECTDIR}/tiempo_Quemador.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/configuraciones.o ${OBJECTDIR}/main.o ${OBJECTDIR}/Memoria.o ${OBJECTDIR}/rutinas_genericas.o ${OBJECTDIR}/timer.o ${OBJECTDIR}/i2cEmem.o ${OBJECTDIR}/ctrl_param.o ${OBJECTDIR}/recepcion_serie.o ${OBJECTDIR}/parametrizacion.o ${OBJECTDIR}/pulso_watch.o ${OBJECTDIR}/APQ.o ${OBJECTDIR}/automatico.o ${OBJECTDIR}/manual.o ${OBJECTDIR}/quemador.o ${OBJECTDIR}/molino.o ${OBJECTDIR}/precalentador.o ${OBJECTDIR}/generar_palabra_A.o ${OBJECTDIR}/sonidosAlarma.o ${OBJECTDIR}/tiempo_Quemador.o

# Source Files
SOURCEFILES=configuraciones.c main.c Memoria.c rutinas_genericas.c timer.c i2cEmem.c ctrl_param.c recepcion_serie.c parametrizacion.c pulso_watch.c APQ.c automatico.c manual.c quemador.c molino.c precalentador.c generar_palabra_A.c sonidosAlarma.c tiempo_Quemador.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/inicio_v2_.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=33FJ256MC710
MP_LINKER_FILE_OPTION=,--script=p33FJ256MC710.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/configuraciones.o: configuraciones.c  .generated_files/flags/default/2b0be6d241512573b83d8fd5613ce3a87d8656ac .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/configuraciones.o.d 
	@${RM} ${OBJECTDIR}/configuraciones.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  configuraciones.c  -o ${OBJECTDIR}/configuraciones.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/configuraciones.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/cad7cde1c17a3f1bf796cb5dd09659caec8df151 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Memoria.o: Memoria.c  .generated_files/flags/default/1c621253b4ede6139edf32a7d9c45430070626d9 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Memoria.o.d 
	@${RM} ${OBJECTDIR}/Memoria.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Memoria.c  -o ${OBJECTDIR}/Memoria.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Memoria.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/rutinas_genericas.o: rutinas_genericas.c  .generated_files/flags/default/39a52db91fbb56fdd628007acada263af4283fd7 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/rutinas_genericas.o.d 
	@${RM} ${OBJECTDIR}/rutinas_genericas.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  rutinas_genericas.c  -o ${OBJECTDIR}/rutinas_genericas.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/rutinas_genericas.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/timer.o: timer.c  .generated_files/flags/default/7058113c97b292d65de0a212d635ad499cfd05d7 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/timer.o.d 
	@${RM} ${OBJECTDIR}/timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  timer.c  -o ${OBJECTDIR}/timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/timer.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/i2cEmem.o: i2cEmem.c  .generated_files/flags/default/a9296e622978c1428446e62fb2aa04ea7e808e96 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/i2cEmem.o.d 
	@${RM} ${OBJECTDIR}/i2cEmem.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  i2cEmem.c  -o ${OBJECTDIR}/i2cEmem.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/i2cEmem.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/ctrl_param.o: ctrl_param.c  .generated_files/flags/default/cc39242abe111cefe806de06d126ae8b2265023c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ctrl_param.o.d 
	@${RM} ${OBJECTDIR}/ctrl_param.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ctrl_param.c  -o ${OBJECTDIR}/ctrl_param.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/ctrl_param.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/recepcion_serie.o: recepcion_serie.c  .generated_files/flags/default/92a892ec6fc5ea3620f9bf5774d832d5839df9f7 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/recepcion_serie.o.d 
	@${RM} ${OBJECTDIR}/recepcion_serie.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  recepcion_serie.c  -o ${OBJECTDIR}/recepcion_serie.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/recepcion_serie.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/parametrizacion.o: parametrizacion.c  .generated_files/flags/default/92f5232d4f650aede4e164ed684083cb1db610a5 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/parametrizacion.o.d 
	@${RM} ${OBJECTDIR}/parametrizacion.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  parametrizacion.c  -o ${OBJECTDIR}/parametrizacion.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/parametrizacion.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/pulso_watch.o: pulso_watch.c  .generated_files/flags/default/8fa552665f12786664c23e6ffad6132575d1401b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/pulso_watch.o.d 
	@${RM} ${OBJECTDIR}/pulso_watch.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  pulso_watch.c  -o ${OBJECTDIR}/pulso_watch.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/pulso_watch.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/APQ.o: APQ.c  .generated_files/flags/default/c46d67122df6dffba5344c9ea3ac74b04ad69902 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/APQ.o.d 
	@${RM} ${OBJECTDIR}/APQ.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  APQ.c  -o ${OBJECTDIR}/APQ.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/APQ.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/automatico.o: automatico.c  .generated_files/flags/default/2280778331e8d895617314e22dc8f86a9748861 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/automatico.o.d 
	@${RM} ${OBJECTDIR}/automatico.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  automatico.c  -o ${OBJECTDIR}/automatico.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/automatico.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/manual.o: manual.c  .generated_files/flags/default/879559a8e67649eff8bc3e3a9878ea5a6d62fbc3 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/manual.o.d 
	@${RM} ${OBJECTDIR}/manual.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  manual.c  -o ${OBJECTDIR}/manual.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/manual.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/quemador.o: quemador.c  .generated_files/flags/default/bdef5752bbbde60800464df1cdd66318de454551 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/quemador.o.d 
	@${RM} ${OBJECTDIR}/quemador.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  quemador.c  -o ${OBJECTDIR}/quemador.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/quemador.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/molino.o: molino.c  .generated_files/flags/default/bb63d4f95d5680705401ee9207b26b03f0e020aa .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/molino.o.d 
	@${RM} ${OBJECTDIR}/molino.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  molino.c  -o ${OBJECTDIR}/molino.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/molino.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/precalentador.o: precalentador.c  .generated_files/flags/default/2e66bd1a84e952abac8bdfdd4a77d2b7ed831dbb .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/precalentador.o.d 
	@${RM} ${OBJECTDIR}/precalentador.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  precalentador.c  -o ${OBJECTDIR}/precalentador.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/precalentador.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/generar_palabra_A.o: generar_palabra_A.c  .generated_files/flags/default/a2b2e1151d63695be8197a0fc4c4c1990dea2710 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/generar_palabra_A.o.d 
	@${RM} ${OBJECTDIR}/generar_palabra_A.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  generar_palabra_A.c  -o ${OBJECTDIR}/generar_palabra_A.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/generar_palabra_A.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sonidosAlarma.o: sonidosAlarma.c  .generated_files/flags/default/26472d4639cf781f4cf33c795d5b1da9f3584957 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/sonidosAlarma.o.d 
	@${RM} ${OBJECTDIR}/sonidosAlarma.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sonidosAlarma.c  -o ${OBJECTDIR}/sonidosAlarma.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sonidosAlarma.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/tiempo_Quemador.o: tiempo_Quemador.c  .generated_files/flags/default/dd0c94cfd59ff7963bbc4921effa6365ef69a335 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/tiempo_Quemador.o.d 
	@${RM} ${OBJECTDIR}/tiempo_Quemador.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  tiempo_Quemador.c  -o ${OBJECTDIR}/tiempo_Quemador.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/tiempo_Quemador.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/configuraciones.o: configuraciones.c  .generated_files/flags/default/707a28f4aa32be55f5cb829b9ffdfc8550a0662 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/configuraciones.o.d 
	@${RM} ${OBJECTDIR}/configuraciones.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  configuraciones.c  -o ${OBJECTDIR}/configuraciones.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/configuraciones.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/dda8bf1e822e3d1e80212e12191b93bc769a2759 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Memoria.o: Memoria.c  .generated_files/flags/default/bbc1a31326fd49bdae1d536d590c2f5bd14d22db .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Memoria.o.d 
	@${RM} ${OBJECTDIR}/Memoria.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Memoria.c  -o ${OBJECTDIR}/Memoria.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Memoria.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/rutinas_genericas.o: rutinas_genericas.c  .generated_files/flags/default/cd07660c12539e68704c8e3b8a4e4176bc6efe77 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/rutinas_genericas.o.d 
	@${RM} ${OBJECTDIR}/rutinas_genericas.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  rutinas_genericas.c  -o ${OBJECTDIR}/rutinas_genericas.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/rutinas_genericas.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/timer.o: timer.c  .generated_files/flags/default/533a0b71c7fc77d555173b8351d59ebe72311c2b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/timer.o.d 
	@${RM} ${OBJECTDIR}/timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  timer.c  -o ${OBJECTDIR}/timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/timer.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/i2cEmem.o: i2cEmem.c  .generated_files/flags/default/3d3857f52009eb795e8d7f1f6fa78fec4c5d746e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/i2cEmem.o.d 
	@${RM} ${OBJECTDIR}/i2cEmem.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  i2cEmem.c  -o ${OBJECTDIR}/i2cEmem.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/i2cEmem.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/ctrl_param.o: ctrl_param.c  .generated_files/flags/default/9b64123db7017e20b8dbfb8b4bb87287464c9a4f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ctrl_param.o.d 
	@${RM} ${OBJECTDIR}/ctrl_param.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ctrl_param.c  -o ${OBJECTDIR}/ctrl_param.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/ctrl_param.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/recepcion_serie.o: recepcion_serie.c  .generated_files/flags/default/fc8314a93e5d4fc176a48e53ab9051c794ad71f9 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/recepcion_serie.o.d 
	@${RM} ${OBJECTDIR}/recepcion_serie.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  recepcion_serie.c  -o ${OBJECTDIR}/recepcion_serie.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/recepcion_serie.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/parametrizacion.o: parametrizacion.c  .generated_files/flags/default/5e62f4cd3f933c6eb3b147ac9bf4a6ddafb7358e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/parametrizacion.o.d 
	@${RM} ${OBJECTDIR}/parametrizacion.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  parametrizacion.c  -o ${OBJECTDIR}/parametrizacion.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/parametrizacion.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/pulso_watch.o: pulso_watch.c  .generated_files/flags/default/b71fbf8ec78641245402e71bb3a3031e84d26da3 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/pulso_watch.o.d 
	@${RM} ${OBJECTDIR}/pulso_watch.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  pulso_watch.c  -o ${OBJECTDIR}/pulso_watch.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/pulso_watch.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/APQ.o: APQ.c  .generated_files/flags/default/40a8a43570a457b8563fa8fe2b90856c581af783 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/APQ.o.d 
	@${RM} ${OBJECTDIR}/APQ.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  APQ.c  -o ${OBJECTDIR}/APQ.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/APQ.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/automatico.o: automatico.c  .generated_files/flags/default/5d81f749473d733e5fd4d2c6587fae20f49e3a8e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/automatico.o.d 
	@${RM} ${OBJECTDIR}/automatico.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  automatico.c  -o ${OBJECTDIR}/automatico.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/automatico.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/manual.o: manual.c  .generated_files/flags/default/d12c0a535d9ba03928072877603cb0748a51020a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/manual.o.d 
	@${RM} ${OBJECTDIR}/manual.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  manual.c  -o ${OBJECTDIR}/manual.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/manual.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/quemador.o: quemador.c  .generated_files/flags/default/326af5dd8aba726dac475d97353e742cd2142227 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/quemador.o.d 
	@${RM} ${OBJECTDIR}/quemador.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  quemador.c  -o ${OBJECTDIR}/quemador.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/quemador.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/molino.o: molino.c  .generated_files/flags/default/7b64225ec28120a0ce44774f2bd43efd90f78c7c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/molino.o.d 
	@${RM} ${OBJECTDIR}/molino.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  molino.c  -o ${OBJECTDIR}/molino.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/molino.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/precalentador.o: precalentador.c  .generated_files/flags/default/edbb4ebdf43ab3a87f51c782fcf6e7fc9d53bc26 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/precalentador.o.d 
	@${RM} ${OBJECTDIR}/precalentador.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  precalentador.c  -o ${OBJECTDIR}/precalentador.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/precalentador.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/generar_palabra_A.o: generar_palabra_A.c  .generated_files/flags/default/5794f65cebd3260ed5416963f3d7545a6edf79ef .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/generar_palabra_A.o.d 
	@${RM} ${OBJECTDIR}/generar_palabra_A.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  generar_palabra_A.c  -o ${OBJECTDIR}/generar_palabra_A.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/generar_palabra_A.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sonidosAlarma.o: sonidosAlarma.c  .generated_files/flags/default/8e5cc1238a57c8179c6a8039d76103f5996079d9 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/sonidosAlarma.o.d 
	@${RM} ${OBJECTDIR}/sonidosAlarma.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sonidosAlarma.c  -o ${OBJECTDIR}/sonidosAlarma.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sonidosAlarma.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/tiempo_Quemador.o: tiempo_Quemador.c  .generated_files/flags/default/f29d568e58f91cbfcc52d7a5095433d4eab34ec2 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/tiempo_Quemador.o.d 
	@${RM} ${OBJECTDIR}/tiempo_Quemador.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  tiempo_Quemador.c  -o ${OBJECTDIR}/tiempo_Quemador.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/tiempo_Quemador.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/inicio_v2_.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/inicio_v2_.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -mreserve=data@0x800:0x81F -mreserve=data@0x820:0x821 -mreserve=data@0x822:0x823 -mreserve=data@0x824:0x825 -mreserve=data@0x826:0x84F   -Wl,,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,--defsym=__MPLAB_DEBUGGER_ICD3=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
${DISTDIR}/inicio_v2_.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/inicio_v2_.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}\\xc16-bin2hex ${DISTDIR}/inicio_v2_.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp="${DFP_DIR}/xc16" 
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
