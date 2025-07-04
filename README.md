# Qiansai25_MainCode
An integrated intelligent pharmacy warehouse that integrates medication management.集用药管理平台的一体化药仓

![QQ截图20250622031556](https://github.com/user-attachments/assets/26797abc-387c-4e21-9396-c810db961317)

主控采用STM32F407vgt6，

运算使用STM32H750vbt6，

电控使用的是芯片是STM32G431cbt6！

This project designed an integrated intelligent medicine warehouse for personal home use and hospital commercialization. The main functions of this medicine warehouse include intelligent visual recognition, custom storage and automatic drug pick-up, automatic human body induction switching power supply, adjustable medication and drug pick-up time reminder, independent drug contraindication reminder, medication calendar recording and analysis, cloud platform data storage...... For long-term drug users or those who have more drug storage needs, the use of the integrated medicine warehouse of this project can greatly reduce the time of drug search, and can know the health index of their long-term medication in real time. The main control of the drug warehouse designed in this project uses the STM32H7 series of high-performance microprocessors for the calculation of the "lightweight AI model", and feeds back the analyzed medication information to the main control STM32F407 for processing. The main control is separated from the motor that actually drives the drug dispensing mechanism, and its operation is controlled by wireless transparent transmission. In addition, we have also developed a "embedded GUI interface" and a "mobile phone APP" suitable for the use of medicine warehouses, and we have also developed medicine warehouses to store user data for the cloud platform and share it with other devices.


本项目设计了一款面向个人家用和医院商用的**一体化智能药仓**，旨在通过智能化技术解决药品管理中的痛点问题。系统以STM32H7系列高性能微处理器为核心，搭载轻量化AI视觉识别模型，可自动识别药品的形态、颜色和包装特征，实现药品的智能分类与入库管理。同时，主控STM32F407负责协调药仓的机电控制系统，通过无线透传模块与执行机构通信，实现药品的精准抓取和配送。

药仓配备多模态传感器阵列，包括红外人体感应模块、重量检测单元和环境监测传感器，可智能感知用户接近自动唤醒系统，并实时监控药品存储环境（温湿度、光照等）。创新设计的**服药智能提醒系统**支持自定义服药时间设置，通过语音播报、LED指示灯和手机APP推送三重提醒方式，确保用户按时服药。系统还能基于药品数据库自动分析药物配伍禁忌，在取药时提供安全警示。

为提升用户体验，我们开发了**嵌入式图形化操作界面**，采用触控屏实现交互，支持药品信息查询、服药记录查看等功能。配套的**跨平台手机APP**（支持iOS/Android）允许用户远程管理药仓、设置服药计划，并生成可视化的服药健康报告。所有数据通过MQTT协议同步至OneNET云平台，实现多设备间的数据共享和长期健康趋势分析，为慢性病患者和家庭医生提供决策支持。

在机械结构方面，药仓采用模块化设计，抽屉式药格可根据药品尺寸灵活调整，伺服电机驱动的机械臂配合高精度导轨实现药品的平稳取放。系统还预留了扩展接口，可兼容医院HIS系统或智能家居平台，满足家庭医疗和机构场景的不同需求。通过这一创新设计，我们期望能显著提升长期服药患者的用药依从性，减少人为用药错误，并为智慧医疗和健康管理提供可靠的硬件支持。

This project designs an integrated intelligent medicine warehouse for personal household and hospital commercialization, aiming to solve the pain points in drug management through intelligent technology. The system is based on the STM32H7 series of high-performance microprocessors and is equipped with a lightweight AI visual recognition model, which can automatically identify the shape, color and packaging characteristics of drugs, and realize the intelligent classification and storage management of drugs. At the same time, the main control STM32F407 is responsible for coordinating the electromechanical control system of the medicine warehouse, and communicates with the actuator through the wireless transparent transmission module to achieve accurate grasping and distribution of drugs.

The pharmacy warehouse is equipped with a multi-modal sensor array, including an infrared human body sensing module, a weight detection unit and an environmental monitoring sensor, which can intelligently perceive the automatic wake-up system when the user is approaching, and monitor the drug storage environment (temperature, humidity, light, etc.) in real time. The innovatively designed intelligent medication reminder system supports custom medication time settings, and ensures that users take their medication on time through voice broadcasting, LED indicators and mobile APP push triple reminders. The system can also automatically analyze drug compatibility contraindications based on the drug database, and provide safety warnings when taking drugs.

In order to improve the user experience, we have developed an embedded graphical operation interface, which uses a touch screen to achieve interaction, and supports functions such as drug information query and medication record viewing. The companion cross-platform mobile app (iOS/Android supported) allows users to remotely manage the pharmacy, set up medication schedules, and generate visual medication health reports. All data is synchronized to the OneNET cloud platform through the MQTT protocol to achieve data sharing and long-term health trend analysis between multiple devices, and provide decision-making support for patients with chronic diseases and family doctors.

In terms of mechanical structure, the medicine warehouse adopts a modular design, the drawer-type medicine compartment can be flexibly adjusted according to the size of the drug, and the robotic arm driven by the servo motor cooperates with the high-precision guide rail to achieve smooth access and placement of drugs. The system also reserves an expansion interface, which can be compatible with hospital HIS system or smart home platform to meet the different needs of home medical and institutional scenarios. Through this innovative design, we expect to significantly improve medication compliance for patients taking long-term medications, reduce human medication errors, and provide reliable hardware support for smart healthcare and health management.
