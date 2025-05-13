# The Computational Arithmetic Logic CALC (CALC)

This is a 15-bit signed calculator implemented in SystemVerilog during the Spring 2025 semester for Intro to SoCET 2. This project includes synthesizable source code, testbenches for simulation, and has been hardened through OpenLane 2 to be taped out.

## Features
1. 15-bit signed integer capability
2. Supports addition, subtraction, and multiplication
3. Keypad-capable input
4. 15 bit LED binary output

## Deployments
1. FPGA tested on Altera Cyclone IV board
2. Built and generated GDSii file using OpenLane 2

## RTL Diagram
![Block Diagram](docs/CALC_block_diagram.png)

## Module Overview
This project has three main module groups, with the input and general controllers being instantiated in the top module and the ALU in the general controller.

**Input Controller** - Scans keypad, debounces and decodes keypad press, then sends digit, operator, and equals sign to the general controller to interact with the ALU

**General Controller** - Main FSM, works with keypad input and builds operands and expression to be computed in ALU, then finally displays output using 16 LEDs

**ALU (Addition/ Multiplication/ Signed Operations)** - Computes expressions given by general controller with magnitude based signing

## Simulation & Verification
This project was extensively verified using testbenches and GTKWave for waveform visualization.

### Testbench Details
- located in `/testbench`
- tests cover:
    - Digit-by-digit keypad entry (including negative and multiple digits)
    - Operator key handling (add, sub, mult)
    - FSM transitions (operand collection, computation, result displaying)
    - Edge cases (e.g. 0, overflow, negative x negative)
 
Example test cases:

For `calculator_top` in `/testbench/calculator_top_tb.sv`
```
    run_calc_sequence(1, 3, KEY_MULT, 1, 4, 12); // -3 * -4 = 12
    run_calc_sequence(0, 63, KEY_MULT, 0, 41, 2583); // 63 * 41 = 2583
    run_calc_sequence(0, 456, KEY_MULT, 0, 0, 0); // 456 * 0 = 0
```

Output:
![Testbench Test Cases](docs/calculator_top_tb_tests.png)

## Authors
1. Nicholas Zhang
2. Lucas Mallen
3. Amogh Havanagi
4. Matthew Du
5. Jeet Jagad

## Step 4: Compiling, Synthesizing, and Simulating

Include all source code (.sv and .v files) of your design inside the `source` folder. Include all testbench code (.sv and .v files) of your design inside the `testbench` folder. Each module in your top level design should be in its own `<module-name>.sv` file where `<module-name>` is the name of the module contained in the file. Similarly, the testbench for each module should be in its own `<module_name>_tb.sv` file. Take a look at the example design provided. File `example_counter.sv` contains module example_counter, and file `example_counter_tb.sv` contains the testbench for example_counter.

To compile and simulate the source version of module example_counter, run `make sim_example_counter_src`. The testbench will run, and you'll see any output on your terminal. In general, you can compile and simulate the source version of a design with name `%` by running `make sim_%_src`.

To synthesize the example_counter design, run `make syn_example_counter`. A folder called `mapped` is created and the Verilog code of the synthesized design (example_counter.v) is placed there. You can synthesize any design of name `%` by running `make syn_%`.

Run `sim_example_counter_syn` to compile and simulate the synthesized design. The testbench will simulate the synthesized version instead of the source version this time. You can run `make sim_%_syn` to compile the synthesized design of name `%`.

## Step 5: Viewing Waves and Debugging
Once you've simulated your design, either source or synthesized, you can open the waveforms for viewing or debugging by using the `waves_%` target. So, if the design is example_counter, you would run `make waves_example_counter`. An error will appear if the design hasn't been compiled and simulated yet.

## Additional notes
- Use `make clean` to remove any temporary files from synthesis, compilation, and simulation.
- Use `make veryclean` to remove all temporary files AND PDK files.
- Run `make help` for more information on all the Makefile targets.
- Add documentation for your project under `/docs`. Check out `docs/info.md` for more instructions.

## Flashing on the FPGA
Details about which FPGA to use are still being figured out. Once the decision has been made, targets to flash your design on the FPGA will be included.

## [Optional]: Setting Up Connection to Visual Studio Code
[Github](https://docs.github.com/en/authentication/connecting-to-github-with-ssh/generating-a-new-ssh-key-and-adding-it-to-the-ssh-agent) has excellent instructions for setting up an SSH key. You'll get a `private` and `public` key, differentiated by the suffix `.pub` on the `public` key. You can use your private key with the following commands:

```
eval `ssh-agent`                        # start the ssh agent
ssh-add ~/.ssh/{your private key file}  # add your ssh key to the agent
```

It's probably smart to add these to your `~/.bashrc` file so that they run every time you open your terminal.

Once you've got a key, you'll want to set up a config entry for Visual Studio Code. If you don't have it, download the `Remote Explorer` extension on VSCode. Open it up, then click `Open SSH Config File`. SSH config entries generally look like this:

```
Host {name of the entry}
    HostName {the address of the ssh server}
    User {username on the ssh server}
    IdentityFile {filepath of your private key}
```

Make entries for both `ececomp` and `asicfab`. For me (Miguel), they look like this:

```
Host ececomp
    HostName ececomp.ecn.purdue.edu
    User misrrael                          # here you use your Purdue username
    IdentityFile ~/.ssh/id_rsa

Host asicfab
    HostName asicfab.ecn.purdue.edu
    User misrrael                       # here you use your SoCET username
    IdentityFile ~/.ssh/id_rsa
    ProxyJump ececomp                   # you can't directly ssh into asicfab, 
                                        # so we use ececomp as a proxy 
```

These endpoints will show up in the vscode remote explorer or you can use them through the terminal like:

```
ssh ececomp
ssh asicfab
```

To get them to work, you'll need to copy the contents of your public key file into the `~/.ssh/authorized_keys` file on ececomp and asicfab. Without the SSH key, you can connect to these servers using your password. You may need to create the `.ssh` directory and `authorized_keys` file.

Once you've copied your `public` key onto a server you should be able to SSH in without using a password.
