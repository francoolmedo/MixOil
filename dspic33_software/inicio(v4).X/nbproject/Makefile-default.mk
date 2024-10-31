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
FINAL_IMAGE=${DISTDIR}/inicio_v4_.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/inicio_v4_.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/inicio_v4_.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=33FJ256MC710
MP_LINKER_FILE_OPTION=,--script=p33FJ256MC710.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/configuraciones.o: configuraciones.c  .generated_files/flags/default/aefaefeec31a77593fdd66567143c620f55209b8 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/configuraciones.o.d 
	@${RM} ${OBJECTDIR}/configuraciones.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  configuraciones.c  -o ${OBJECTDIR}/configuraciones.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/configuraciones.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/540e85c2ca5ffc67160703cb1d396fd95524eba .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Memoria.o: Memoria.c  .generated_files/flags/default/7741251fe642f58b145732be5077397aed53da1 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Memoria.o.d 
	@${RM} ${OBJECTDIR}/Memoria.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Memoria.c  -o ${OBJECTDIR}/Memoria.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Memoria.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/rutinas_genericas.o: rutinas_genericas.c  .generated_files/flags/default/a6258e5058f666fa23b4455416e99f1cf8bcbfc3 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/rutinas_genericas.o.d 
	@${RM} ${OBJECTDIR}/rutinas_genericas.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  rutinas_genericas.c  -o ${OBJECTDIR}/rutinas_genericas.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/rutinas_genericas.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/timer.o: timer.c  .generated_files/flags/default/a9e9af0eac1aab0f50e8e8987be770e4bc8efe01 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/timer.o.d 
	@${RM} ${OBJECTDIR}/timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  timer.c  -o ${OBJECTDIR}/timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/timer.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/i2cEmem.o: i2cEmem.c  .generated_files/flags/default/d69114544d745a5568462c3048726e7ecffc5c3c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/i2cEmem.o.d 
	@${RM} ${OBJECTDIR}/i2cEmem.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  i2cEmem.c  -o ${OBJECTDIR}/i2cEmem.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/i2cEmem.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/ctrl_param.o: ctrl_param.c  .generated_files/flags/default/ac5f0260e06eccb81f751e23f191f89b6690fee1 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ctrl_param.o.d 
	@${RM} ${OBJECTDIR}/ctrl_param.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ctrl_param.c  -o ${OBJECTDIR}/ctrl_param.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/ctrl_param.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/recepcion_serie.o: recepcion_serie.c  .generated_files/flags/default/2021d028b3bddf16518fd65f7241612d65354a18 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/recepcion_serie.o.d 
	@${RM} ${OBJECTDIR}/recepcion_serie.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  recepcion_serie.c  -o ${OBJECTDIR}/recepcion_serie.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/recepcion_serie.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/parametrizacion.o: parametrizacion.c  .generated_files/flags/default/7c1e43f31360c6ba23d949fedce545ff916d2bf3 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/parametrizacion.o.d 
	@${RM} ${OBJECTDIR}/parametrizacion.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  parametrizacion.c  -o ${OBJECTDIR}/parametrizacion.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/parametrizacion.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/pulso_watch.o: pulso_watch.c  .generated_files/flags/default/36f2e7d2133b137bd74199fe78fd5c0b1b6ed7bb .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/pulso_watch.o.d 
	@${RM} ${OBJECTDIR}/pulso_watch.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  pulso_watch.c  -o ${OBJECTDIR}/pulso_watch.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/pulso_watch.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/APQ.o: APQ.c  .generated_files/flags/default/84b38235ecfd1eca29fae8cf167d1d9737c2bbb0 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/APQ.o.d 
	@${RM} ${OBJECTDIR}/APQ.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  APQ.c  -o ${OBJECTDIR}/APQ.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/APQ.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/automatico.o: automatico.c  .generated_files/flags/default/f48c5f99ea102ca1e41700492b47edbd9da36253 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/automatico.o.d 
	@${RM} ${OBJECTDIR}/automatico.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  automatico.c  -o ${OBJECTDIR}/automatico.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/automatico.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/manual.o: manual.c  .generated_files/flags/default/d5b86ab0caa3c9406885c7f1e7066f57a6ffe222 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/manual.o.d 
	@${RM} ${OBJECTDIR}/manual.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  manual.c  -o ${OBJECTDIR}/manual.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/manual.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/quemador.o: quemador.c  .generated_files/flags/default/6486034ef88ec57db1075acc68970a83de84c53d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/quemador.o.d 
	@${RM} ${OBJECTDIR}/quemador.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  quemador.c  -o ${OBJECTDIR}/quemador.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/quemador.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/molino.o: molino.c  .generated_files/flags/default/660dfb8f79282642af475e7aea0dbe6b6bb958d3 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/molino.o.d 
	@${RM} ${OBJECTDIR}/molino.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  molino.c  -o ${OBJECTDIR}/molino.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/molino.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/precalentador.o: precalentador.c  .generated_files/flags/default/425e6f2b9a33f4a0c9c8b7585ba09d7ef92c81c4 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/precalentador.o.d 
	@${RM} ${OBJECTDIR}/precalentador.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  precalentador.c  -o ${OBJECTDIR}/precalentador.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/precalentador.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/generar_palabra_A.o: generar_palabra_A.c  .generated_files/flags/default/e1c548abb63f2443f5b7ebb404c2d26bcd03661d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/generar_palabra_A.o.d 
	@${RM} ${OBJECTDIR}/generar_palabra_A.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  generar_palabra_A.c  -o ${OBJECTDIR}/generar_palabra_A.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/generar_palabra_A.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sonidosAlarma.o: sonidosAlarma.c  .generated_files/flags/default/fdf16fdb50fb227fb998819ab5b6f9e7c06564e2 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/sonidosAlarma.o.d 
	@${RM} ${OBJECTDIR}/sonidosAlarma.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sonidosAlarma.c  -o ${OBJECTDIR}/sonidosAlarma.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sonidosAlarma.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/tiempo_Quemador.o: tiempo_Quemador.c  .generated_files/flags/default/924fb21e40d3fae8e61b2fc16316da161216fe3b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/tiempo_Quemador.o.d 
	@${RM} ${OBJECTDIR}/tiempo_Quemador.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  tiempo_Quemador.c  -o ${OBJECTDIR}/tiempo_Quemador.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/tiempo_Quemador.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/configuraciones.o: configuraciones.c  .generated_files/flags/default/202d50316628ec6383c84d6abe4fb3bd8aaf0786 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/configuraciones.o.d 
	@${RM} ${OBJECTDIR}/configuraciones.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  configuraciones.c  -o ${OBJECTDIR}/configuraciones.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/configuraciones.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/5e47de5c27e335fe06c063c1965bc8c9b4358339 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Memoria.o: Memoria.c  .generated_files/flags/default/149cbbdcc9f7693ade2083ce856e40f3edf36607 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Memoria.o.d 
	@${RM} ${OBJECTDIR}/Memoria.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Memoria.c  -o ${OBJECTDIR}/Memoria.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Memoria.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/rutinas_genericas.o: rutinas_genericas.c  .generated_files/flags/default/715f5cc281fdf82c34665e723895464a1c070d14 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/rutinas_genericas.o.d 
	@${RM} ${OBJECTDIR}/rutinas_genericas.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  rutinas_genericas.c  -o ${OBJECTDIR}/rutinas_genericas.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/rutinas_genericas.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/timer.o: timer.c  .generated_files/flags/default/1869e54dfc03cb13759913fc5eafc6863ac03a0e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/timer.o.d 
	@${RM} ${OBJECTDIR}/timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  timer.c  -o ${OBJECTDIR}/timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/timer.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/i2cEmem.o: i2cEmem.c  .generated_files/flags/default/fef8c165bcdf4785c136232a367c2b15d2be6a77 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/i2cEmem.o.d 
	@${RM} ${OBJECTDIR}/i2cEmem.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  i2cEmem.c  -o ${OBJECTDIR}/i2cEmem.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/i2cEmem.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/ctrl_param.o: ctrl_param.c  .generated_files/flags/default/f223740ba3591963dd1d81708a6f221f9dd69725 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ctrl_param.o.d 
	@${RM} ${OBJECTDIR}/ctrl_param.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ctrl_param.c  -o ${OBJECTDIR}/ctrl_param.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/ctrl_param.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/recepcion_serie.o: recepcion_serie.c  .generated_files/flags/default/e1ce2686200acaa89d73d4f3a74acea9c4c4e441 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/recepcion_serie.o.d 
	@${RM} ${OBJECTDIR}/recepcion_serie.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  recepcion_serie.c  -o ${OBJECTDIR}/recepcion_serie.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/recepcion_serie.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/parametrizacion.o: parametrizacion.c  .generated_files/flags/default/a6625cd7e84e5e4fe565a7a8ed4743cce91810c2 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/parametrizacion.o.d 
	@${RM} ${OBJECTDIR}/parametrizacion.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  parametrizacion.c  -o ${OBJECTDIR}/parametrizacion.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/parametrizacion.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/pulso_watch.o: pulso_watch.c  .generated_files/flags/default/c92545fe6975b66fbb36724e5d130cd72d3d0c9b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/pulso_watch.o.d 
	@${RM} ${OBJECTDIR}/pulso_watch.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  pulso_watch.c  -o ${OBJECTDIR}/pulso_watch.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/pulso_watch.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/APQ.o: APQ.c  .generated_files/flags/default/16b46f47840cb594d408b80055d824a9ce1ede9f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/APQ.o.d 
	@${RM} ${OBJECTDIR}/APQ.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  APQ.c  -o ${OBJECTDIR}/APQ.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/APQ.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/automatico.o: automatico.c  .generated_files/flags/default/a3053aafd29d8f46063a778e425b651fe218ff55 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/automatico.o.d 
	@${RM} ${OBJECTDIR}/automatico.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  automatico.c  -o ${OBJECTDIR}/automatico.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/automatico.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/manual.o: manual.c  .generated_files/flags/default/8bf0aeef31bea4a5af2d023576e0dae429cabac8 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/manual.o.d 
	@${RM} ${OBJECTDIR}/manual.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  manual.c  -o ${OBJECTDIR}/manual.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/manual.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/quemador.o: quemador.c  .generated_files/flags/default/368ac495710d696f7b63bb160d2a00d256765c44 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/quemador.o.d 
	@${RM} ${OBJECTDIR}/quemador.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  quemador.c  -o ${OBJECTDIR}/quemador.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/quemador.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/molino.o: molino.c  .generated_files/flags/default/e8795e629df7a381dfbd355184122a5c46294142 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/molino.o.d 
	@${RM} ${OBJECTDIR}/molino.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  molino.c  -o ${OBJECTDIR}/molino.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/molino.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/precalentador.o: precalentador.c  .generated_files/flags/default/ed11baf46dc26f204bdac772a101ac3fdd10e23a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/precalentador.o.d 
	@${RM} ${OBJECTDIR}/precalentador.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  precalentador.c  -o ${OBJECTDIR}/precalentador.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/precalentador.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/generar_palabra_A.o: generar_palabra_A.c  .generated_files/flags/default/c17cffc8c95a47991209d105401a303242381692 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/generar_palabra_A.o.d 
	@${RM} ${OBJECTDIR}/generar_palabra_A.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  generar_palabra_A.c  -o ${OBJECTDIR}/generar_palabra_A.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/generar_palabra_A.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sonidosAlarma.o: sonidosAlarma.c  .generated_files/flags/default/69c3e4bf698c0ab7c3b69624122535721ffac6a8 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/sonidosAlarma.o.d 
	@${RM} ${OBJECTDIR}/sonidosAlarma.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sonidosAlarma.c  -o ${OBJECTDIR}/sonidosAlarma.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sonidosAlarma.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/tiempo_Quemador.o: tiempo_Quemador.c  .generated_files/flags/default/8b5edf91ed032da2cbddf79b116a46b9ca8e03d4 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
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
${DISTDIR}/inicio_v4_.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/inicio_v4_.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -mreserve=data@0x800:0x81F -mreserve=data@0x820:0x821 -mreserve=data@0x822:0x823 -mreserve=data@0x824:0x825 -mreserve=data@0x826:0x84F   -Wl,,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,--defsym=__MPLAB_DEBUGGER_ICD3=1,$(MP_LINKER_FILE_OPTION),--heap=1024,--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
${DISTDIR}/inicio_v4_.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/inicio_v4_.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--heap=1024,--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}\\xc16-bin2hex ${DISTDIR}/inicio_v4_.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp="${DFP_DIR}/xc16" 
	
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
