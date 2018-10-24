##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=TP1
ConfigurationName      :=Debug
WorkspacePath          :=/Users/Jeremie/Git/CppTP1/TP1
ProjectPath            :=/Users/Jeremie/Git/CppTP1/TP1/TP1
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Jeremie Ricard
Date                   :=19/10/2018
CodeLitePath           :="/Users/Jeremie/Library/Application Support/CodeLite"
LinkerName             :=g++
SharedObjectLinkerName :=g++ -dynamiclib -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="TP1.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/Applications/codelite.app/Contents/SharedSupport/
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/MesOptions.cpp$(ObjectSuffix) $(IntermediateDirectory)/MesFichiers.cpp$(ObjectSuffix) $(IntermediateDirectory)/Menu.cpp$(ObjectSuffix) $(IntermediateDirectory)/LesParties.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/Jeremie/Git/CppTP1/TP1/TP1/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/MesOptions.cpp$(ObjectSuffix): MesOptions.cpp $(IntermediateDirectory)/MesOptions.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/Jeremie/Git/CppTP1/TP1/TP1/MesOptions.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/MesOptions.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/MesOptions.cpp$(DependSuffix): MesOptions.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/MesOptions.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/MesOptions.cpp$(DependSuffix) -MM MesOptions.cpp

$(IntermediateDirectory)/MesOptions.cpp$(PreprocessSuffix): MesOptions.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/MesOptions.cpp$(PreprocessSuffix) MesOptions.cpp

$(IntermediateDirectory)/MesFichiers.cpp$(ObjectSuffix): MesFichiers.cpp $(IntermediateDirectory)/MesFichiers.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/Jeremie/Git/CppTP1/TP1/TP1/MesFichiers.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/MesFichiers.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/MesFichiers.cpp$(DependSuffix): MesFichiers.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/MesFichiers.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/MesFichiers.cpp$(DependSuffix) -MM MesFichiers.cpp

$(IntermediateDirectory)/MesFichiers.cpp$(PreprocessSuffix): MesFichiers.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/MesFichiers.cpp$(PreprocessSuffix) MesFichiers.cpp

$(IntermediateDirectory)/Menu.cpp$(ObjectSuffix): Menu.cpp $(IntermediateDirectory)/Menu.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/Jeremie/Git/CppTP1/TP1/TP1/Menu.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Menu.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Menu.cpp$(DependSuffix): Menu.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Menu.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Menu.cpp$(DependSuffix) -MM Menu.cpp

$(IntermediateDirectory)/Menu.cpp$(PreprocessSuffix): Menu.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Menu.cpp$(PreprocessSuffix) Menu.cpp

$(IntermediateDirectory)/LesParties.cpp$(ObjectSuffix): LesParties.cpp $(IntermediateDirectory)/LesParties.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/Jeremie/Git/CppTP1/TP1/TP1/LesParties.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/LesParties.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/LesParties.cpp$(DependSuffix): LesParties.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/LesParties.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/LesParties.cpp$(DependSuffix) -MM LesParties.cpp

$(IntermediateDirectory)/LesParties.cpp$(PreprocessSuffix): LesParties.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/LesParties.cpp$(PreprocessSuffix) LesParties.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


