# zephyr-blink
WS2812 blink example with Zephyr RTOS on esp32c6 board
___

## Table of contents
- [Project description](#project-description)
- [Install](#install)
- [Use](#use)
___

## Project Description
The goal of this project is to provide footing to familiarize yourself with the Zephyr project. Specifically with out of SDK managed projects.  
By default, after downloading and installing Zephyr, sample projects are built from within the zephyr repositories. Since this is not a flexible file location and the overhead from it is insanely big, this project aims to break out the sample into a standalone project directory and minimise the overhead from updating the west based project while providing some practice with how Zephyr constructs projects.
___

## Install
In order to start working with the repository, first make sure the dependencies are met. This readme will cover the required steps for Windows installations. For other OS installations, please refer to the original Zephyr Project documentation.  

### Prepare dependencies
Run the following line:
```
winget install Kitware.CMake Ninja-build.Ninja oss-winget.gperf Python.Python.3.12 Git.Git oss-winget.dtc wget 7zip.7zip
```

### Prepare virtual environment
Make sure Python 3.12+ is installed before continuing.
```
cd $Env:HOMEPATH
python -m venv zephyrproject\.venv
```
Potentially you'll need to set the execution policy to allow activating the virtual environment.
```
Set-ExecutionPolicy -ExecutionPolicy RemoteSigned -Scope CurrentUser

```
Activate virtual environment.
```
zephyrproject\.venv\Scripts\Activate.ps1
```
___
### Install and initialize west
```
pip install west
cd $Env:homepath
west init zephyrproject
cd zephyrproject
west update
```
NOTE: This process can take a VERY long time. For Chinese netizens, please consider adjusting the west.yml file inside the zephyr directory. Change:
```
From: url-base: https://github.com/zephyrproject-rtos
To: url-base: https://gitee.com/zephyrproject-rtos-cnmirror
```
Then execute the following commands:
```
west zephyr-export
python -m pip install @((west packages pip) -split ' ')
cd $Env:HOMEPATH\zephyrproject\zephyr
west sdk install
```
Verify the Zephyr installation by building a blinky example. Since this repository is going to be focused on building for esp32, verify building for target esp32c6.
```
cd samples/simple/blinky
west build -p always -b esp32c6
```
If this builds successfully, please continue on.
___
### West init this repository.
Navigate to a desired workspace directory and init the project.
```
mkdir -p $Env:homepath/projects
cd $Env:homespath/projects
west init -m https://github.com/SoftwareShenzheneer/zephyr-blink.git zephyr-blink
```
___

## Use
Run the following command to build and flash for esp32c6:
```
west build -p always -b esp32c6_devkitc/esp32c6/hpcore
west flash
```

