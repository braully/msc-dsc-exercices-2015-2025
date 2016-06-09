#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/estrutura-dados/Heap.o \
	${OBJECTDIR}/estrutura-dados/Lista.o \
	${OBJECTDIR}/simulacao.o \
	${OBJECTDIR}/tipo/EventoPessoa.o \
	${OBJECTDIR}/tipo/Pessoa.o \
	${OBJECTDIR}/tipo/PessoaFila.o \
	${OBJECTDIR}/tipo/Tempo.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f2 \
	${TESTDIR}/TestFiles/f1

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/simulador-edpa

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/simulador-edpa: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/simulador-edpa ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/estrutura-dados/Heap.o: estrutura-dados/Heap.cpp 
	${MKDIR} -p ${OBJECTDIR}/estrutura-dados
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/estrutura-dados/Heap.o estrutura-dados/Heap.cpp

${OBJECTDIR}/estrutura-dados/Lista.o: estrutura-dados/Lista.cpp 
	${MKDIR} -p ${OBJECTDIR}/estrutura-dados
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/estrutura-dados/Lista.o estrutura-dados/Lista.cpp

${OBJECTDIR}/simulacao.o: simulacao.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/simulacao.o simulacao.cpp

${OBJECTDIR}/tipo/EventoPessoa.o: tipo/EventoPessoa.cpp 
	${MKDIR} -p ${OBJECTDIR}/tipo
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/tipo/EventoPessoa.o tipo/EventoPessoa.cpp

${OBJECTDIR}/tipo/Pessoa.o: tipo/Pessoa.cpp 
	${MKDIR} -p ${OBJECTDIR}/tipo
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/tipo/Pessoa.o tipo/Pessoa.cpp

${OBJECTDIR}/tipo/PessoaFila.o: tipo/PessoaFila.cpp 
	${MKDIR} -p ${OBJECTDIR}/tipo
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/tipo/PessoaFila.o tipo/PessoaFila.cpp

${OBJECTDIR}/tipo/Tempo.o: tipo/Tempo.cpp 
	${MKDIR} -p ${OBJECTDIR}/tipo
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/tipo/Tempo.o tipo/Tempo.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${TESTDIR}/TestFiles/f2: ${TESTDIR}/tests/distribuicaoExponencial.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f2 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/TesteEstruturaDados.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} 


${TESTDIR}/tests/distribuicaoExponencial.o: tests/distribuicaoExponencial.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/distribuicaoExponencial.o tests/distribuicaoExponencial.cpp


${TESTDIR}/tests/TesteEstruturaDados.o: tests/TesteEstruturaDados.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/TesteEstruturaDados.o tests/TesteEstruturaDados.cpp


${OBJECTDIR}/estrutura-dados/Heap_nomain.o: ${OBJECTDIR}/estrutura-dados/Heap.o estrutura-dados/Heap.cpp 
	${MKDIR} -p ${OBJECTDIR}/estrutura-dados
	@NMOUTPUT=`${NM} ${OBJECTDIR}/estrutura-dados/Heap.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/estrutura-dados/Heap_nomain.o estrutura-dados/Heap.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/estrutura-dados/Heap.o ${OBJECTDIR}/estrutura-dados/Heap_nomain.o;\
	fi

${OBJECTDIR}/estrutura-dados/Lista_nomain.o: ${OBJECTDIR}/estrutura-dados/Lista.o estrutura-dados/Lista.cpp 
	${MKDIR} -p ${OBJECTDIR}/estrutura-dados
	@NMOUTPUT=`${NM} ${OBJECTDIR}/estrutura-dados/Lista.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/estrutura-dados/Lista_nomain.o estrutura-dados/Lista.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/estrutura-dados/Lista.o ${OBJECTDIR}/estrutura-dados/Lista_nomain.o;\
	fi

${OBJECTDIR}/simulacao_nomain.o: ${OBJECTDIR}/simulacao.o simulacao.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/simulacao.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/simulacao_nomain.o simulacao.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/simulacao.o ${OBJECTDIR}/simulacao_nomain.o;\
	fi

${OBJECTDIR}/tipo/EventoPessoa_nomain.o: ${OBJECTDIR}/tipo/EventoPessoa.o tipo/EventoPessoa.cpp 
	${MKDIR} -p ${OBJECTDIR}/tipo
	@NMOUTPUT=`${NM} ${OBJECTDIR}/tipo/EventoPessoa.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/tipo/EventoPessoa_nomain.o tipo/EventoPessoa.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/tipo/EventoPessoa.o ${OBJECTDIR}/tipo/EventoPessoa_nomain.o;\
	fi

${OBJECTDIR}/tipo/Pessoa_nomain.o: ${OBJECTDIR}/tipo/Pessoa.o tipo/Pessoa.cpp 
	${MKDIR} -p ${OBJECTDIR}/tipo
	@NMOUTPUT=`${NM} ${OBJECTDIR}/tipo/Pessoa.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/tipo/Pessoa_nomain.o tipo/Pessoa.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/tipo/Pessoa.o ${OBJECTDIR}/tipo/Pessoa_nomain.o;\
	fi

${OBJECTDIR}/tipo/PessoaFila_nomain.o: ${OBJECTDIR}/tipo/PessoaFila.o tipo/PessoaFila.cpp 
	${MKDIR} -p ${OBJECTDIR}/tipo
	@NMOUTPUT=`${NM} ${OBJECTDIR}/tipo/PessoaFila.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/tipo/PessoaFila_nomain.o tipo/PessoaFila.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/tipo/PessoaFila.o ${OBJECTDIR}/tipo/PessoaFila_nomain.o;\
	fi

${OBJECTDIR}/tipo/Tempo_nomain.o: ${OBJECTDIR}/tipo/Tempo.o tipo/Tempo.cpp 
	${MKDIR} -p ${OBJECTDIR}/tipo
	@NMOUTPUT=`${NM} ${OBJECTDIR}/tipo/Tempo.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/tipo/Tempo_nomain.o tipo/Tempo.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/tipo/Tempo.o ${OBJECTDIR}/tipo/Tempo_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f2 || true; \
	    ${TESTDIR}/TestFiles/f1 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/simulador-edpa

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
