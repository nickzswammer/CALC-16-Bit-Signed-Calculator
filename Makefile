##############################################################################
# Intro to SoCET No. 2 - General Makefile
# Author: Miguel Isrrael Teran
##############################################################################

# For students:
# Review this Makefile carefully before making any changes

##############################################################################
# Variables
##############################################################################

# Shell (we use Bash)
SHELL := /bin/bash

# Variables for PDK Installation
export PDK_ROOT := $(PWD)/pdks
export PDK := sky130A
export PDK_PATH := $(PDK_ROOT)/$(PDK)
export PDK_VERSION_TAG := 0fe599b2afb6708d281543108caf8310912f54af

# Directories of source, testbench, and mapped code
SRC := source
TB	:= testbench
MAP := mapped

# Location of executables
BUILD := sim_build

# EDA Tools and Flags
# We'll be using different tools for the source and synthesized simulations
SIM_SRC_TOOL := verilator
SIM_SYN_TOOL := iverilog
SYNTH_TOOL := yosys

# Standard Cell Libraries
LIBERTY := $(PDK_PATH)/libs.ref/sky130_fd_sc_hd/lib/sky130_fd_sc_hd__tt_100C_1v80.lib
VERILOG := $(PDK_PATH)/libs.ref/sky130_fd_sc_hd/verilog/primitives.v $(PDK_PATH)/libs.ref/sky130_fd_sc_hd/verilog/sky130_fd_sc_hd.v

# FPGA Variables - COMING SOON!

##############################################################################
# Administrative Targets
##############################################################################
# Display information about Makefile targets
.PHONY: help
help:
	@echo "----------------------------------------------------------------"
	@echo "|                       Makefile Targets                       |"
	@echo "----------------------------------------------------------------"
	@echo "Administrative targets:"
	@echo "  help          - Displays info about the Makefile targets"
	@echo "  setup_pdk     - Setup the required sky130A PDK files"
	@echo "  check_env     - Check environment - PDK and Yosys must be"
	@echo "                  loaded"
	@echo "  clean         - Remove all temporary files from simulation"
	@echo "                  and compilation"
	@echo "  veryclean     - Removes all temporary files, including the"
	@echo "                  PDK files"
	@echo
	@echo "Compilation & Simulation targets:"
	@echo "  sim_%_src     - Compiles and simulates source version of"
	@echo "                  design with top level name %"
	@echo "  syn_%         - Synthesizes design with top level name %"
	@echo "  sim_%_syn     - Runs synthesis, and compiles and simulates"
	@echo "                  synthesized version of design with top"
	@echo "                  level name %"
	@echo
	@echo "FPGA targets:"
	@echo "  None yet, but coming soon!"
	@echo
	@echo "Miscellaneous targets:"
	@echo "  vlint_%       - Lints design of top level name %"
	@echo "  waves_%       - Opens waveforms dump of design %"
	@echo "                  after simulation using GTKWave"
	@echo "----------------------------------------------------------------"


# Setup PDK Files
.PHONY: setup_pdk
setup_pdk:
	@python3 -m pip install --user --upgrade --no-cache-dir volare &&\
	mkdir -p pdks && \
	volare enable --pdk sky130 $(PDK_VERSION_TAG) &&\
	echo -e "\nPDK Setup Complete!\n"

# Check environment (PDK and SYNTH_TOOL must be loaded)
.PHONY: check_env
check_env:
	@if [ -z "$$(ls -A $(PDK_ROOT) 2>/dev/null)" ]; then \
		echo -e "\nERROR: PDK not found! Have you run \"make setup_pdk\"?\n" >&2; exit 1; \
	elif ! module is-loaded $(SYNTH_TOOL); then \
		echo -e "\nERROR: $(SYNTH_TOOL) is not loaded! Have you added \"module load $(SYNTH_TOOL)\" to your .bashrc?\n" >&2; exit 1; \
	else \
		echo -e "\nEnvironment setup correctly!\n"; \
	fi

# Simple Cleaning (removes all temporary files)
.PHONY: clean
clean:
	@rm -rf $(BUILD)
	@rm -rf $(MAP)
	@rm -f *.log
	@rm -f *.vcd
	@echo -e "\nRemoved temporary files, build files, and log files.\n"

# Thorough cleaning (remove all PDK files)
.PHONY: veryclean
veryclean: clean
	@rm -rf $(PDK_ROOT) &&\
	echo -e "PDK files removed!\n"

##############################################################################
# Compilation & Simulation Targets
##############################################################################
# Source Compilation and simulation
.PHONY: sim_%_src
sim_%_src: 
	@echo -e "Creating executable for source simulation...\n\n"
	@mkdir -p $(BUILD) && rm -rf $(BUILD)/*
	@$(SIM_SRC_TOOL) -binary -j 0 --Mdir $(BUILD) --trace -y $(SRC) $(TB)/$*_tb.sv
	@echo -e "\nSource Compilation complete!\n"
	@echo -e "Simulating source...\n"
	@$(BUILD)/V$*_tb
	@echo -e "\nSimulation complete!\n"

# Run synthesis on Design
.PHONY: syn_%
syn_%: check_env
	@echo -e "Synthesizing design...\n"
	@mkdir -p $(MAP)
	@$(SYNTH_TOOL) -d -p 'read_verilog -sv -Idir $(SRC) $(SRC)/$*.sv; synth -top $*; dfflibmap -liberty $(LIBERTY); abc -liberty $(LIBERTY); clean; write_verilog -noattr -noexpr -nohex -nodec -defparam $(MAP)/$*.v' > $*.log
	@echo -e "\nSynthesis complete!\n"

# Compile and simulate synthesized design
.PHONY: sim_%_syn
sim_%_syn: syn_%
	@echo -e "Compiling synthesized design...\n\n"
	@mkdir -p $(BUILD) && rm -rf $(BUILD)/*
	@$(SIM_SYN_TOOL) -g2012 -o $(BUILD)/$*_tb -DFUNCTIONAL -DUNIT_DELAY=#1 $(TB)/$*_tb.sv $(MAP)/$*.v $(VERILOG)
	@echo -e "\nCompilation complete!\n"
	@echo -e "Simulating synthesized design...\n\n"
	@vvp -l vvp_sim.log $(BUILD)/$*_tb
	@echo -e "\nSimulation complete!\n"

##############################################################################
# FPGA Targets
##############################################################################

# Coming Soon!

##############################################################################
# Miscellaneous Targets
##############################################################################
# Lint Design Only
.PHONY: vlint_%
vlint_%:
	$(SIM_SRC_TOOL) --lint-only -Wall -y $(SRC) $(SRC)/$*.sv
	@echo -e "\nNo linting errors found!\n"

# Open Waveforms in GTKWave for debugging
.PHONY: waves_%
waves_%:
	@if [ -e $*.vcd ]; then \
		gtkwave $*.vcd; \
	else \
		echo "ERROR: Design $* has not been simulated yet!" >&2; \
		exit 1; \
	fi
