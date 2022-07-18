@echo off
REM ****************************************************************************
REM Vivado (TM) v2020.1.1 (64-bit)
REM
REM Filename    : simulate.bat
REM Simulator   : Xilinx Vivado Simulator
REM Description : Script for simulating the design by launching the simulator
REM
REM Generated by Vivado on Thu Sep 24 15:42:49 -0700 2020
REM SW Build 2960000 on Wed Aug  5 22:57:20 MDT 2020
REM
REM Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
REM
REM usage: simulate.bat
REM
REM ****************************************************************************
echo "xsim EE214_Proj3Chal2_test_fixture_behav -key {Behavioral:sim_1:Functional:EE214_Proj3Chal2_test_fixture} -tclbatch EE214_Proj3Chal2_test_fixture.tcl -log simulate.log"
call xsim  EE214_Proj3Chal2_test_fixture_behav -key {Behavioral:sim_1:Functional:EE214_Proj3Chal2_test_fixture} -tclbatch EE214_Proj3Chal2_test_fixture.tcl -log simulate.log
if "%errorlevel%"=="0" goto SUCCESS
if "%errorlevel%"=="1" goto END
:END
exit 1
:SUCCESS
exit 0
