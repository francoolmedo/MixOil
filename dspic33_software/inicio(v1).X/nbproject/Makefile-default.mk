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
FINAL_IMAGE=${DISTDIR}/inicio_v1_.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/inicio_v1_.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED=configuraciones.c main.c Memoria.c rutinas_genericas.c timer.c i2cEmem.c ctrl_param.c recepcion_serie.c parametrizacion.c pulso_watch.c APQ.c automatico.c manual.c quemador.c molino.c precalentador.c borrar.c generar_palabra_A.c sonidosAlarma.c tiempo_Quemador.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/configuraciones.o ${OBJECTDIR}/main.o ${OBJECTDIR}/Memoria.o ${OBJECTDIR}/rutinas_genericas.o ${OBJECTDIR}/timer.o ${OBJECTDIR}/i2cEmem.o ${OBJECTDIR}/ctrl_param.o ${OBJECTDIR}/recepcion_serie.o ${OBJECTDIR}/parametrizacion.o ${OBJECTDIR}/pulso_watch.o ${OBJECTDIR}/APQ.o ${OBJECTDIR}/automatico.o ${OBJECTDIR}/manual.o ${OBJECTDIR}/quemador.o ${OBJECTDIR}/molino.o ${OBJECTDIR}/precalentador.o ${OBJECTDIR}/borrar.o ${OBJECTDIR}/generar_palabra_A.o ${OBJECTDIR}/sonidosAlarma.o ${OBJECTDIR}/tiempo_Quemador.o
POSSIBLE_DEPFILES=${OBJECTDIR}/configuraciones.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/Memoria.o.d ${OBJECTDIR}/rutinas_genericas.o.d ${OBJECTDIR}/timer.o.d ${OBJECTDIR}/i2cEmem.o.d ${OBJECTDIR}/ctrl_param.o.d ${OBJECTDIR}/recepcion_serie.o.d ${OBJECTDIR}/parametrizacion.o.d ${OBJECTDIR}/pulso_watch.o.d ${OBJECTDIR}/APQ.o.d ${OBJECTDIR}/automatico.o.d ${OBJECTDIR}/manual.o.d ${OBJECTDIR}/quemador.o.d ${OBJECTDIR}/molino.o.d ${OBJECTDIR}/precalentador.o.d ${OBJECTDIR}/borrar.o.d ${OBJECTDIR}/generar_palabra_A.o.d ${OBJECTDIR}/sonidosAlarma.o.d ${OBJECTDIR}/tiempo_Quemador.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/configuraciones.o ${OBJECTDIR}/main.o ${OBJECTDIR}/Memoria.o ${OBJECTDIR}/rutinas_genericas.o ${OBJECTDIR}/timer.o ${OBJECTDIR}/i2cEmem.o ${OBJECTDIR}/ctrl_param.o ${OBJECTDIR}/recepcion_serie.o ${OBJECTDIR}/parametrizacion.o ${OBJECTDIR}/pulso_watch.o ${OBJECTDIR}/APQ.o ${OBJECTDIR}/automatico.o ${OBJECTDIR}/manual.o ${OBJECTDIR}/quemador.o ${OBJECTDIR}/molino.o ${OBJECTDIR}/precalentador.o ${OBJECTDIR}/borrar.o ${OBJECTDIR}/generar_palabra_A.o ${OBJECTDIR}/sonidosAlarma.o ${OBJECTDIR}/tiempo_Quemador.o

# Source Files
SOURCEFILES=configuraciones.c main.c Memoria.c rutinas_genericas.c timer.c i2cEmem.c ctrl_param.c recepcion_serie.c parametrizacion.c pulso_watch.c APQ.c automatico.c manual.c quemador.c molino.c precalentador.c borrar.c generar_palabra_A.c sonidosAlarma.c tiempo_Quemador.c



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
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/inicio_v1_.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=33FJ256MC710
MP_LINKER_FILE_OPTION=,--script=p33FJ256MC710.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/configuraciones.o: configuraciones.c  .generated_files/flags/default/3f4ee106ce8a441e5971f55af53a05c944ec688e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/configuraciones.o.d 
	@${RM} ${OBJECTDIR}/configuraciones.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  configuraciones.c  -o ${OBJECTDIR}/configuraciones.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/configuraciones.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/bb76432c5bdc707f89be02a98ce244027ccb28b2 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Memoria.o: Memoria.c  .generated_files/flags/default/477e5dd86dc722b4e836780e1d83b61c639adb3b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Memoria.o.d 
	@${RM} ${OBJECTDIR}/Memoria.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Memoria.c  -o ${OBJECTDIR}/Memoria.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Memoria.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/rutinas_genericas.o: rutinas_genericas.c  .generated_files/flags/default/4364e04b478100b60c98896489040ba35bd10b15 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/rutinas_genericas.o.d 
	@${RM} ${OBJECTDIR}/rutinas_genericas.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  rutinas_genericas.c  -o ${OBJECTDIR}/rutinas_genericas.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/rutinas_genericas.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/timer.o: timer.c  .generated_files/flags/default/1c579cb526ab7a08c89674d0faebda3c451ce69d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/timer.o.d 
	@${RM} ${OBJECTDIR}/timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  timer.c  -o ${OBJECTDIR}/timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/timer.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/i2cEmem.o: i2cEmem.c  .generated_files/flags/default/57b4194d86ce33077c6e59cacca12f36a3fee69d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/i2cEmem.o.d 
	@${RM} ${OBJECTDIR}/i2cEmem.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  i2cEmem.c  -o ${OBJECTDIR}/i2cEmem.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/i2cEmem.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/ctrl_param.o: ctrl_param.c  .generated_files/flags/default/a2f1763e796c717abef4b1b11f40e673f3a87f46 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ctrl_param.o.d 
	@${RM} ${OBJECTDIR}/ctrl_param.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ctrl_param.c  -o ${OBJECTDIR}/ctrl_param.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/ctrl_param.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/recepcion_serie.o: recepcion_serie.c  .generated_files/flags/default/8748466b68ac987c2043650c9791df57d45c2684 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/recepcion_serie.o.d 
	@${RM} ${OBJECTDIR}/recepcion_serie.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  recepcion_serie.c  -o ${OBJECTDIR}/recepcion_serie.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/recepcion_serie.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/parametrizacion.o: parametrizacion.c  .generated_files/flags/default/401ef50ecceac12737afbe4142fae9836fd81107 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/parametrizacion.o.d 
	@${RM} ${OBJECTDIR}/parametrizacion.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  parametrizacion.c  -o ${OBJECTDIR}/parametrizacion.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/parametrizacion.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/pulso_watch.o: pulso_watch.c  .generated_files/flags/default/1f4cb17ba2464a2d483e017ecd066d787607b3af .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/pulso_watch.o.d 
	@${RM} ${OBJECTDIR}/pulso_watch.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  pulso_watch.c  -o ${OBJECTDIR}/pulso_watch.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/pulso_watch.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/APQ.o: APQ.c  .generated_files/flags/default/f9799f8ce3aa4a3c97aae34b3c589e6442c1cf94 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/APQ.o.d 
	@${RM} ${OBJECTDIR}/APQ.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  APQ.c  -o ${OBJECTDIR}/APQ.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/APQ.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/automatico.o: automatico.c  .generated_files/flags/default/2fd3a4e06049849c62297ac602c01ff99ec516e2 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/automatico.o.d 
	@${RM} ${OBJECTDIR}/automatico.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  automatico.c  -o ${OBJECTDIR}/automatico.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/automatico.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/manual.o: manual.c  .generated_files/flags/default/b03c064f88b72a369bc0f2cb4a693f9fcc8931b8 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/manual.o.d 
	@${RM} ${OBJECTDIR}/manual.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  manual.c  -o ${OBJECTDIR}/manual.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/manual.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/quemador.o: quemador.c  .generated_files/flags/default/6a01dd3c6542c007091d073d00628b16291d8fec .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/quemador.o.d 
	@${RM} ${OBJECTDIR}/quemador.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  quemador.c  -o ${OBJECTDIR}/quemador.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/quemador.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/molino.o: molino.c  .generated_files/flags/default/8cb1aeb779a6297468ad8b60b865e7cc1f46605f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/molino.o.d 
	@${RM} ${OBJECTDIR}/molino.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  molino.c  -o ${OBJECTDIR}/molino.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/molino.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/precalentador.o: precalentador.c  .generated_files/flags/default/c9679a643ec52a6f56a3a39e987661689d3a16d1 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/precalentador.o.d 
	@${RM} ${OBJECTDIR}/precalentador.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  precalentador.c  -o ${OBJECTDIR}/precalentador.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/precalentador.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/borrar.o: borrar.c  .generated_files/flags/default/233f03bbbc6445c027f59e3faf6c583d0b00fd41 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/borrar.o.d 
	@${RM} ${OBJECTDIR}/borrar.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  borrar.c  -o ${OBJECTDIR}/borrar.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/borrar.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/generar_palabra_A.o: generar_palabra_A.c  .generated_files/flags/default/ccfdce53f204f6d6dc3081cb4398cf8fd8b1b84d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/generar_palabra_A.o.d 
	@${RM} ${OBJECTDIR}/generar_palabra_A.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  generar_palabra_A.c  -o ${OBJECTDIR}/generar_palabra_A.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/generar_palabra_A.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sonidosAlarma.o: sonidosAlarma.c  .generated_files/flags/default/b47b6626c58389bf566fdb3f1664f2a2ffa5f2fb .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/sonidosAlarma.o.d 
	@${RM} ${OBJECTDIR}/sonidosAlarma.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sonidosAlarma.c  -o ${OBJECTDIR}/sonidosAlarma.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sonidosAlarma.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/tiempo_Quemador.o: tiempo_Quemador.c  .generated_files/flags/default/7de92858a9a04567185a8e45a516eecffb241177 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/tiempo_Quemador.o.d 
	@${RM} ${OBJECTDIR}/tiempo_Quemador.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  tiempo_Quemador.c  -o ${OBJECTDIR}/tiempo_Quemador.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/tiempo_Quemador.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/configuraciones.o: configuraciones.c  .generated_files/flags/default/49925f31b9541d6287bed30883aa40ac7f533161 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/configuraciones.o.d 
	@${RM} ${OBJECTDIR}/configuraciones.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  configuraciones.c  -o ${OBJECTDIR}/configuraciones.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/configuraciones.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/bc9f6723fd9863f6fb4db7c4bd7a2626972d4b1c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Memoria.o: Memoria.c  .generated_files/flags/default/69aee06c63581ac68fd6c90c6e6aaa0388c3f48e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Memoria.o.d 
	@${RM} ${OBJECTDIR}/Memoria.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Memoria.c  -o ${OBJECTDIR}/Memoria.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Memoria.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/rutinas_genericas.o: rutinas_genericas.c  .generated_files/flags/default/8ac3a7858fc52b254b91815fe9b2af1ac56cfdd8 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/rutinas_genericas.o.d 
	@${RM} ${OBJECTDIR}/rutinas_genericas.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  rutinas_genericas.c  -o ${OBJECTDIR}/rutinas_genericas.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/rutinas_genericas.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/timer.o: timer.c  .generated_files/flags/default/49846026dbb13fad8ccc8251475de7e13b8cdb57 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/timer.o.d 
	@${RM} ${OBJECTDIR}/timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  timer.c  -o ${OBJECTDIR}/timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/timer.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/i2cEmem.o: i2cEmem.c  .generated_files/flags/default/4767cee3b758d315f55feccf4753da9403ef58a6 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/i2cEmem.o.d 
	@${RM} ${OBJECTDIR}/i2cEmem.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  i2cEmem.c  -o ${OBJECTDIR}/i2cEmem.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/i2cEmem.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/ctrl_param.o: ctrl_param.c  .generated_files/flags/default/1bb1ae911f8515c71822e4cb687f4631bd157a3c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ctrl_param.o.d 
	@${RM} ${OBJECTDIR}/ctrl_param.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ctrl_param.c  -o ${OBJECTDIR}/ctrl_param.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/ctrl_param.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/recepcion_serie.o: recepcion_serie.c  .generated_files/flags/default/37ad18b8c840ae7919296e158ded364922415ce4 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/recepcion_serie.o.d 
	@${RM} ${OBJECTDIR}/recepcion_serie.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  recepcion_serie.c  -o ${OBJECTDIR}/recepcion_serie.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/recepcion_serie.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/parametrizacion.o: parametrizacion.c  .generated_files/flags/default/303bc4a9b2924d3fe9b2d93a2478b5a800c6d419 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/parametrizacion.o.d 
	@${RM} ${OBJECTDIR}/parametrizacion.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  parametrizacion.c  -o ${OBJECTDIR}/parametrizacion.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/parametrizacion.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/pulso_watch.o: pulso_watch.c  .generated_files/flags/default/b64867967d41fba04fe8fb9efd6da68e831df0f3 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/pulso_watch.o.d 
	@${RM} ${OBJECTDIR}/pulso_watch.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  pulso_watch.c  -o ${OBJECTDIR}/pulso_watch.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/pulso_watch.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/APQ.o: APQ.c  .generated_files/flags/default/50341ef555be225469b327b3a389fe19821ba4d8 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/APQ.o.d 
	@${RM} ${OBJECTDIR}/APQ.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  APQ.c  -o ${OBJECTDIR}/APQ.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/APQ.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/automatico.o: automatico.c  .generated_files/flags/default/9145691dbcec96a4ed70d1548555974ab01e5888 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/automatico.o.d 
	@${RM} ${OBJECTDIR}/automatico.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  automatico.c  -o ${OBJECTDIR}/automatico.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/automatico.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/manual.o: manual.c  .generated_files/flags/default/60aab3ae23cbc97b67d40dc286b93098cbd38e56 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/manual.o.d 
	@${RM} ${OBJECTDIR}/manual.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  manual.c  -o ${OBJECTDIR}/manual.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/manual.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/quemador.o: quemador.c  .generated_files/flags/default/bf56c432f6445deef08bb1b3f21a8447145a4e8e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/quemador.o.d 
	@${RM} ${OBJECTDIR}/quemador.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  quemador.c  -o ${OBJECTDIR}/quemador.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/quemador.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/molino.o: molino.c  .generated_files/flags/default/cf34a03dd26aad54955a3621da36fb89f350769 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/molino.o.d 
	@${RM} ${OBJECTDIR}/molino.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  molino.c  -o ${OBJECTDIR}/molino.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/molino.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/precalentador.o: precalentador.c  .generated_files/flags/default/e3bea569441cd1ae75e7051549b21fcdf6229048 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/precalentador.o.d 
	@${RM} ${OBJECTDIR}/precalentador.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  precalentador.c  -o ${OBJECTDIR}/precalentador.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/precalentador.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/borrar.o: borrar.c  .generated_files/flags/default/199620a909899ffbc25a623006e1681e5285d16f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/borrar.o.d 
	@${RM} ${OBJECTDIR}/borrar.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  borrar.c  -o ${OBJECTDIR}/borrar.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/borrar.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/generar_palabra_A.o: generar_palabra_A.c  .generated_files/flags/default/c6bb5789a21c972d2c56796a3cf1a5278d02b693 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/generar_palabra_A.o.d 
	@${RM} ${OBJECTDIR}/generar_palabra_A.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  generar_palabra_A.c  -o ${OBJECTDIR}/generar_palabra_A.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/generar_palabra_A.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sonidosAlarma.o: sonidosAlarma.c  .generated_files/flags/default/da2cb967d53e370235331c541e26d869d383641f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/sonidosAlarma.o.d 
	@${RM} ${OBJECTDIR}/sonidosAlarma.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sonidosAlarma.c  -o ${OBJECTDIR}/sonidosAlarma.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sonidosAlarma.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/tiempo_Quemador.o: tiempo_Quemador.c  .generated_files/flags/default/93e29f37a77a736b972c772f3c1c34baeca850ff .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
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
${DISTDIR}/inicio_v1_.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/inicio_v1_.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -mreserve=data@0x800:0x81F -mreserve=data@0x820:0x821 -mreserve=data@0x822:0x823 -mreserve=data@0x824:0x825 -mreserve=data@0x826:0x84F   -Wl,,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,--defsym=__MPLAB_DEBUGGER_ICD3=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
${DISTDIR}/inicio_v1_.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/inicio_v1_.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}\\xc16-bin2hex ${DISTDIR}/inicio_v1_.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp="${DFP_DIR}/xc16" 
	
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
