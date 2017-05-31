# Overview 
- STM_AlarmGSM is a project of a stationary alarm system consisting of motion-detector combined with a GSM notification module. The project is executed on STM32Discovery.

# Description 
- The heart of the project is STM32Discovery kit. Along with the features of the board itself, project consists of: SIM800L GSM modem with external source of energy, magnetic contact switch and InfraRed motion sensor HC-SR501. We are using a standard speaker module as well for loud audio alert and button board for operating. The code is written in C language.

# Tools:  

* CoIDE 1.7.8 (www.coocox.org)
* AT Command Tester (http://m2msupport.net/m2msupport/module-tester/)
* Hercules 3-2-8 (http://www.hw-group.com/products/hercules/)

# How to run 
- Assembly the kit and the modules as in scheme. For the proper usage of SIM modem, paid-for Micro SIM card is required. After activating the alarm with the attached button alarm will activate automatically after a short period of time. After detection by either of sensor, a set grace period is granted to deactivate the alarm with the button. If the button is not pressed  within grace period, the alarm will be set, and SMS notification will be sent.

# How to compile 

- Compile and load to STM32F407G using CoIDE 1.7.8

# Future improvements 
- Implementation of PDU coder/decoder for more readable and convinient setting of SMS contents
- More options for controlling the alarm remotely using incoming text messages from 'trusted' phone numbers.

# Attributions:

* STM32 Delay (http://stm32f4-discovery.net/2014/04/library-03-stm32f429-discovery-system-clock-and-pretty-precise-delay-library/ )


# License
 - MIT

# Credits 
- Project created by Mariusz Hajer, Szymon Chojnowski and Piotr Grabowski, students of Computer Science @ Faculty of Electical Engineering, Poznan University of Technology.

- The project was conducted during the Microprocessor Lab course held by the Institute of Control and Information Engineering, Poznan University of Technology.
- Supervisor: Adam Bondyra
