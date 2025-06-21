# Qiansai25_MainCode
An integrated intelligent pharmacy warehouse that integrates medication management.集用药管理平台的一体化药仓

![QQ截图20250622031556](https://github.com/user-attachments/assets/26797abc-387c-4e21-9396-c810db961317)

主控采用STM32F407vgt6，

运算使用STM32H750vbt6，

电控使用的是芯片是STM32G431cbt6！


This project designed an integrated intelligent medicine warehouse for personal home use and hospital commercialization. The main functions of this medicine warehouse include intelligent visual recognition, custom storage and automatic drug pick-up, automatic human body induction switching power supply, adjustable medication and drug pick-up time reminder, independent drug contraindication reminder, medication calendar recording and analysis, cloud platform data storage...... For long-term drug users or those who have more drug storage needs, the use of the integrated medicine warehouse of this project can greatly reduce the time of drug search, and can know the health index of their long-term medication in real time. The main control of the drug warehouse designed in this project uses the STM32H7 series of high-performance microprocessors for the calculation of the "lightweight AI model", and feeds back the analyzed medication information to the main control STM32F407 for processing. The main control is separated from the motor that actually drives the drug dispensing mechanism, and its operation is controlled by wireless transparent transmission. In addition, we have also developed a "embedded GUI interface" and a "mobile phone APP" suitable for the use of medicine warehouses, and we have also developed medicine warehouses to store user data for the cloud platform and share it with other devices.

本项目设计了一款面向于个人家用和医院商用的一体化智能药仓。此药仓主要功能有智能视觉识别、自定义存储和自动拿取药品，自动人体感应开关电源，可调服药取药时间提示，自主药物禁忌提醒，服药日历记录及分析，云平台数据存储......对于长期服药者或有较多药物存储需求者来说，使用本项目的一体化药仓可以极大减少药品查找的时间，并可以实时了解到自己长期服药的健康指数。此次项目设计的药仓主控用到了STM32H7系列高性能微处理器作"轻量化AI模型"的运算，并把分析后的服药信息反馈给主控STM32F407处理。主控与实际驱动药品拿取机构的电机部分分离，使用无线透传控制其运转。此外，我们还配套开发了适合药仓使用的"嵌入式GUI界面"和"上位机手机端APP"，也有开发药仓针对云平台存储用户数据，并实现与其他设备共享。
