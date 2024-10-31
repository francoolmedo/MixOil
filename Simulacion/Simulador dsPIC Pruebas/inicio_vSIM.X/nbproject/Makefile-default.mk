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
FINAL_IMAGE=${DISTDIR}/inicio_vSIM.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/inicio_vSIM.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/inicio_vSIM.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=33FJ256MC710
MP_LINKER_FILE_OPTION=,--script=p33FJ256MC710.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/configuraciones.o: configuraciones.c  .generated_files/flags/default/5bd02574f660590e0fac046f51530286e3fe45dd .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/configuraciones.o.d 
	@${RM} ${OBJECTDIR}/configuraciones.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  configuraciones.c  -o ${OBJECTDIR}/configuraciones.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/configuraciones.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/196f1e3ababf6f8dbeadb58c79c7d929db0f1f0b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Memoria.o: Memoria.c  .generated_files/flags/default/56c9614a87c359085ae217dd51ac65c0de27f12d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Memoria.o.d 
	@${RM} ${OBJECTDIR}/Memoria.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Memoria.c  -o ${OBJECTDIR}/Memoria.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Memoria.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/rutinas_genericas.o: rutinas_genericas.c  .generated_files/flags/default/b7cfaee1a3d42794337cb856a910d860093d5719 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/rutinas_genericas.o.d 
	@${RM} ${OBJECTDIR}/rutinas_genericas.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  rutinas_genericas.c  -o ${OBJECTDIR}/rutinas_genericas.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/rutinas_genericas.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/timer.o: timer.c  .generated_files/flags/default/37ed6146873c88788e74f940e25ced8d83e7aef0 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/timer.o.d 
	@${RM} ${OBJECTDIR}/timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  timer.c  -o ${OBJECTDIR}/timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/timer.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/i2cEmem.o: i2cEmem.c  .generated_files/flags/default/f785f93d2dfd2ef2d912a1099695a11985443a85 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/i2cEmem.o.d 
	@${RM} ${OBJECTDIR}/i2cEmem.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  i2cEmem.c  -o ${OBJECTDIR}/i2cEmem.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/i2cEmem.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/ctrl_param.o: ctrl_param.c  .generated_files/flags/default/53d1ef96053083d434e615256c5c44e8801b478 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ctrl_param.o.d 
	@${RM} ${OBJECTDIR}/ctrl_param.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ctrl_param.c  -o ${OBJECTDIR}/ctrl_param.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/ctrl_param.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/recepcion_serie.o: recepcion_serie.c  .generated_files/flags/default/9dc151e0a10469872787f0c3984d578fbc93deaf .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/recepcion_serie.o.d 
	@${RM} ${OBJECTDIR}/recepcion_serie.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  recepcion_serie.c  -o ${OBJECTDIR}/recepcion_serie.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/recepcion_serie.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/parametrizacion.o: parametrizacion.c  .generated_files/flags/default/aaadb3d271cb2c160e56c2c427340146db826ff7 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/parametrizacion.o.d 
	@${RM} ${OBJECTDIR}/parametrizacion.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  parametrizacion.c  -o ${OBJECTDIR}/parametrizacion.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/parametrizacion.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/pulso_watch.o: pulso_watch.c  .generated_files/flags/default/ffbe27a48f3dada3a62ccef40695e88b83821282 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/pulso_watch.o.d 
	@${RM} ${OBJECTDIR}/pulso_watch.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  pulso_watch.c  -o ${OBJECTDIR}/pulso_watch.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/pulso_watch.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/APQ.o: APQ.c  .generated_files/flags/default/fd99999340a4c049c2acd985dd8e308eefbeae0f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/APQ.o.d 
	@${RM} ${OBJECTDIR}/APQ.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  APQ.c  -o ${OBJECTDIR}/APQ.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/APQ.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/automatico.o: automatico.c  .generated_files/flags/default/f65a0d1fe18ce89188c979e1362720aec83043e5 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/automatico.o.d 
	@${RM} ${OBJECTDIR}/automatico.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  automatico.c  -o ${OBJECTDIR}/automatico.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/automatico.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/manual.o: manual.c  .generated_files/flags/default/bb08fad3c0fbb0008b24aead9bd90e342cc36d88 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/manual.o.d 
	@${RM} ${OBJECTDIR}/manual.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  manual.c  -o ${OBJECTDIR}/manual.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/manual.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/quemador.o: quemador.c  .generated_files/flags/default/2aaae9fc90017da4eb21fcf31ea49c56d6ec5613 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/quemador.o.d 
	@${RM} ${OBJECTDIR}/quemador.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  quemador.c  -o ${OBJECTDIR}/quemador.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/quemador.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/molino.o: molino.c  .generated_files/flags/default/8b03921a9be7feb5771c8196314267829d815d78 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/molino.o.d 
	@${RM} ${OBJECTDIR}/molino.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  molino.c  -o ${OBJECTDIR}/molino.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/molino.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/precalentador.o: precalentador.c  .generated_files/flags/default/586810aba0eb598235451c870977ed48997df8f5 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/precalentador.o.d 
	@${RM} ${OBJECTDIR}/precalentador.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  precalentador.c  -o ${OBJECTDIR}/precalentador.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/precalentador.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/generar_palabra_A.o: generar_palabra_A.c  .generated_files/flags/default/508eed9328d2a9dab9f2efb0bcbcbd8d5a5e4b1c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/generar_palabra_A.o.d 
	@${RM} ${OBJECTDIR}/generar_palabra_A.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  generar_palabra_A.c  -o ${OBJECTDIR}/generar_palabra_A.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/generar_palabra_A.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sonidosAlarma.o: sonidosAlarma.c  .generated_files/flags/default/9a8be511a9a7a8873ec96599bf1c1f939565716a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/sonidosAlarma.o.d 
	@${RM} ${OBJECTDIR}/sonidosAlarma.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sonidosAlarma.c  -o ${OBJECTDIR}/sonidosAlarma.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sonidosAlarma.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/tiempo_Quemador.o: tiempo_Quemador.c  .generated_files/flags/default/8f10bafb48241853540fc31bb2fe6fea6fa9ca5d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/tiempo_Quemador.o.d 
	@${RM} ${OBJECTDIR}/tiempo_Quemador.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  tiempo_Quemador.c  -o ${OBJECTDIR}/tiempo_Quemador.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/tiempo_Quemador.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/configuraciones.o: configuraciones.c  .generated_files/flags/default/d8f534cb56124e76aabb86a508802c25c168dd76 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/configuraciones.o.d 
	@${RM} ${OBJECTDIR}/configuraciones.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  configuraciones.c  -o ${OBJECTDIR}/configuraciones.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/configuraciones.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/636f6aa794830c99d1976830f84f30a9a52cbe96 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Memoria.o: Memoria.c  .generated_files/flags/default/c3bb3f885d7ba90a8740c2c5c6a70ce90441c21a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Memoria.o.d 
	@${RM} ${OBJECTDIR}/Memoria.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Memoria.c  -o ${OBJECTDIR}/Memoria.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Memoria.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/rutinas_genericas.o: rutinas_genericas.c  .generated_files/flags/default/6cf2887a1a48b555ae2580d5979e47b491ff2021 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/rutinas_genericas.o.d 
	@${RM} ${OBJECTDIR}/rutinas_genericas.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  rutinas_genericas.c  -o ${OBJECTDIR}/rutinas_genericas.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/rutinas_genericas.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/timer.o: timer.c  .generated_files/flags/default/1ed284d753cf85b06634b9564aba6bd158bd2c3a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/timer.o.d 
	@${RM} ${OBJECTDIR}/timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  timer.c  -o ${OBJECTDIR}/timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/timer.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/i2cEmem.o: i2cEmem.c  .generated_files/flags/default/59138202a1addf1bea7f0fdb8dfd70e9e85cbd38 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/i2cEmem.o.d 
	@${RM} ${OBJECTDIR}/i2cEmem.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  i2cEmem.c  -o ${OBJECTDIR}/i2cEmem.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/i2cEmem.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/ctrl_param.o: ctrl_param.c  .generated_files/flags/default/24df26bca0f4558712bfdf2084ce68ccdc553f90 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ctrl_param.o.d 
	@${RM} ${OBJECTDIR}/ctrl_param.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ctrl_param.c  -o ${OBJECTDIR}/ctrl_param.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/ctrl_param.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/recepcion_serie.o: recepcion_serie.c  .generated_files/flags/default/e4d574dfc08860f16eb3b36ff12015e9540c7c0e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/recepcion_serie.o.d 
	@${RM} ${OBJECTDIR}/recepcion_serie.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  recepcion_serie.c  -o ${OBJECTDIR}/recepcion_serie.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/recepcion_serie.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/parametrizacion.o: parametrizacion.c  .generated_files/flags/default/247bbc2f056882358c480d45b69469ead0b5925a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/parametrizacion.o.d 
	@${RM} ${OBJECTDIR}/parametrizacion.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  parametrizacion.c  -o ${OBJECTDIR}/parametrizacion.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/parametrizacion.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/pulso_watch.o: pulso_watch.c  .generated_files/flags/default/d180f984b8eaae171522dd42696647c0532552b3 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/pulso_watch.o.d 
	@${RM} ${OBJECTDIR}/pulso_watch.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  pulso_watch.c  -o ${OBJECTDIR}/pulso_watch.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/pulso_watch.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/APQ.o: APQ.c  .generated_files/flags/default/be1d3e5c62dd7e412b388c667d173673552fcc78 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/APQ.o.d 
	@${RM} ${OBJECTDIR}/APQ.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  APQ.c  -o ${OBJECTDIR}/APQ.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/APQ.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/automatico.o: automatico.c  .generated_files/flags/default/270621d32751a58c9e0c779d9a340b06af65be3e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/automatico.o.d 
	@${RM} ${OBJECTDIR}/automatico.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  automatico.c  -o ${OBJECTDIR}/automatico.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/automatico.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/manual.o: manual.c  .generated_files/flags/default/26e10dba8014993a923b18fb3a60ce636da8c449 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/manual.o.d 
	@${RM} ${OBJECTDIR}/manual.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  manual.c  -o ${OBJECTDIR}/manual.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/manual.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/quemador.o: quemador.c  .generated_files/flags/default/147f78ab0b219663ef0e517da4448d4a7c3dbb7a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/quemador.o.d 
	@${RM} ${OBJECTDIR}/quemador.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  quemador.c  -o ${OBJECTDIR}/quemador.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/quemador.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/molino.o: molino.c  .generated_files/flags/default/b7f1d3e45acda9413f3496a2b1c6c4633a9f865e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/molino.o.d 
	@${RM} ${OBJECTDIR}/molino.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  molino.c  -o ${OBJECTDIR}/molino.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/molino.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/precalentador.o: precalentador.c  .generated_files/flags/default/8fdd8326584f78749389b60084054f9e3bb4f6e2 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/precalentador.o.d 
	@${RM} ${OBJECTDIR}/precalentador.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  precalentador.c  -o ${OBJECTDIR}/precalentador.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/precalentador.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/generar_palabra_A.o: generar_palabra_A.c  .generated_files/flags/default/551f50ed0b99e5f56a155d8d175e61971bf3cea0 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/generar_palabra_A.o.d 
	@${RM} ${OBJECTDIR}/generar_palabra_A.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  generar_palabra_A.c  -o ${OBJECTDIR}/generar_palabra_A.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/generar_palabra_A.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sonidosAlarma.o: sonidosAlarma.c  .generated_files/flags/default/7cca010336f4acc32cf2922a3070ff8265a5bb99 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/sonidosAlarma.o.d 
	@${RM} ${OBJECTDIR}/sonidosAlarma.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sonidosAlarma.c  -o ${OBJECTDIR}/sonidosAlarma.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sonidosAlarma.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/tiempo_Quemador.o: tiempo_Quemador.c  .generated_files/flags/default/18a65c6545dd68361c20d52f8b8d84c3b1f09d14 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
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
${DISTDIR}/inicio_vSIM.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/inicio_vSIM.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)      -Wl,,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,--defsym=__MPLAB_DEBUGGER_SIMULATOR=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
${DISTDIR}/inicio_vSIM.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/inicio_vSIM.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}\\xc16-bin2hex ${DISTDIR}/inicio_vSIM.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp="${DFP_DIR}/xc16" 
	
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
