# Qiansai25_MainCode
An integrated intelligent pharmacy warehouse that integrates medication management.集用药管理平台的一体化药仓

[![zread](https://img.shields.io/badge/Ask_Zread-_.svg?style=flat&color=00b0aa&labelColor=000000&logo=data%3Aimage%2Fsvg%2Bxml%3Bbase64%2CPHN2ZyB3aWR0aD0iMTYiIGhlaWdodD0iMTYiIHZpZXdCb3g9IjAgMCAxNiAxNiIgZmlsbD0ibm9uZSIgeG1sbnM9Imh0dHA6Ly93d3cudzMub3JnLzIwMDAvc3ZnIj4KPHBhdGggZD0iTTQuOTYxNTYgMS42MDAxSDIuMjQxNTZDMS44ODgxIDEuNjAwMSAxLjYwMTU2IDEuODg2NjQgMS42MDE1NiAyLjI0MDFWNC45NjAxQzEuNjAxNTYgNS4zMTM1NiAxLjg4ODEgNS42MDAxIDIuMjQxNTYgNS42MDAxSDQuOTYxNTZDNS4zMTUwMiA1LjYwMDEgNS42MDE1NiA1LjMxMzU2IDUuNjAxNTYgNC45NjAxVjIuMjQwMUM1LjYwMTU2IDEuODg2NjQgNS4zMTUwMiAxLjYwMDEgNC45NjE1NiAxLjYwMDFaIiBmaWxsPSIjZmZmIi8%2BCjxwYXRoIGQ9Ik00Ljk2MTU2IDEwLjM5OTlIMi4yNDE1NkMxLjg4ODEgMTAuMzk5OSAxLjYwMTU2IDEwLjY4NjQgMS42MDE1NiAxMS4wMzk5VjEzLjc1OTlDMS42MDE1NiAxNC4xMTM0IDEuODg4MSAxNC4zOTk5IDIuMjQxNTYgMTQuMzk5OUg0Ljk2MTU2QzUuMzE1MDIgMTQuMzk5OSA1LjYwMTU2IDE0LjExMzQgNS42MDE1NiAxMy43NTk5VjExLjAzOTlDNS42MDE1NiAxMC42ODY0IDUuMzE1MDIgMTAuMzk5OSA0Ljk2MTU2IDEwLjM5OTlaIiBmaWxsPSIjZmZmIi8%2BCjxwYXRoIGQ9Ik0xMy43NTg0IDEuNjAwMUgxMS4wMzg0QzEwLjY4NSAxLjYwMDEgMTAuMzk4NCAxLjg4NjY0IDEwLjM5ODQgMi4yNDAxVjQuOTYwMUMxMC4zOTg0IDUuMzEzNTYgMTAuNjg1IDUuNjAwMSAxMS4wMzg0IDUuNjAwMUgxMy43NTg0QzE0LjExMTkgNS42MDAxIDE0LjM5ODQgNS4zMTM1NiAxNC4zOTg0IDQuOTYwMVYyLjI0MDFDMTQuMzk4NCAxLjg4NjY0IDE0LjExMTkgMS42MDAxIDEzLjc1ODQgMS42MDAxWiIgZmlsbD0iI2ZmZiIvPgo8cGF0aCBkPSJNNCAxMkwxMiA0TDQgMTJaIiBmaWxsPSIjZmZmIi8%2BCjxwYXRoIGQ9Ik00IDEyTDEyIDQiIHN0cm9rZT0iI2ZmZiIgc3Ryb2tlLXdpZHRoPSIxLjUiIHN0cm9rZS1saW5lY2FwPSJyb3VuZCIvPgo8L3N2Zz4K&logoColor=ffffff)](https://zread.ai/Sguan-ZhouQing/Qiansai25_MainCode)
https://zread.ai/Sguan-ZhouQing/Qiansai25_MainCode

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


集用药管理平台的一体化智能药仓
STorm小分队；周庆；薛琬莹；钱一程；刘勇
摘要	
本作品“集用药管理平台的一体化智能药仓”基于机电一体化硬件、AI中枢与云端协同网络，实现了药品存储、管理与配送的智能化解决方案。系统以STM32H7高性能处理器为核心，搭载轻量化AI视觉识别模型，结合STM32F407主控与STM32G431电控板，通过多模态传感器（红外对射、压力传感器等）实现药品的精准抓取和配送。机械结构采用模块化分隔设计，支持灵活调整以适应医院药房和家庭健康监护场景。
功能上，系统具备实时环境监控、用户接近感知自动唤醒、多模式服药提醒（语音、LED、APP推送）、药品配伍禁忌分析及嵌入式触控交互界面。配套跨平台手机APP（iOS/Android）支持远程管理，数据通过MQTT协议同步至OneNET云平台，实现多设备协同。
技术层面，项目融合Uinapp、FreeRTOS、STM32CubeAI及LVGL图形化GUI，采用多核异构架构与分布式控制，结合无线/有线通信方式，确保高效稳定的运行。简化传统药物存储流程，降低人力成本；通过智能化管理提升用药安全性与便捷性；模块化设计增强系统扩展性。最终成果通过严格的测试验证，满足药物抓取精度、云端部署等性能指标，为医疗健康领域提供了高效、可靠的物联网应用范例。

第一部分  作品概述
1.1	功能与特性
实现药品的精准抓取和配送，实时监控药品存储环境，智能感知用户接近自动唤醒，服药智能提醒系统可自定义服药时间，通过语音播报、LED指示灯和手机APP推送等提醒方式；系统基于药品数据库自动分析药物配伍禁忌，在取药时提供安全警示；嵌入式图形化操作界面采用触控屏实现交互，提升面向对象的使用体验。
1.2	应用领域
本系统为医疗机构和家庭用药场景提供智能化管理解决方案。在医疗领域，系统通过自动化药品抓取配送、配伍禁忌分析和环境监测三大功能，有效解决传统药房人工管理效率低、易出错的问题…可集成至医院智能药房，实现药品的精准分类、库存实时监控及快速取药。智能化的药品分类与库存监控配合云端数据同步，使管理人员可实时掌握药品信息，优化资源配置。
针对家庭用药场景，系统通过多模式提醒、触控交互和近场感应技术，为老年人和慢性病患者提供便捷的用药管理服务。家庭成员可通过专属APP实现远程监护，确保用药安全。系统兼具专业性与易用性，提供无障碍体验,显著提升医疗和家庭场景的用药管理效率。
1.3	主要技术特点
本系统基于Uinapp框架构建跨平台移动应用，实现iOS/Android双端兼容的用户交互界面，通过FreeRTOS实时操作系统对多任务进行高效调度，确保系统响应实时性。利用STM32Cube.AI工具链部署轻量化AI模型至嵌入式端，实现本地化药品识别与配伍分析，显著降低云端依赖。系统采用LVGL图形化GUI框架开发触控交互界面，优化人机交互体验，同时集成Wi-Fi、蓝牙、I2C、SPI、CAN等多种通信方式，构建灵活可靠的数据传输网络，支持设备间协同与云端数据同步。这一技术架构在保证系统实时性能的同时，实现了实时计算到云端协同的完整解决方案。
1.4	主要性能指标
图像识别准确率，IOT联网成功率，机械臂能够稳定抓取药品的容错率。

1.5	主要创新点
1.	解决了传统药物存储和分类的繁琐流程，简化了人力物力支出。方便药品后期管理和实时用药取药，有效解决传统药房人工管理效率低、易出错的问题。
2.	机械结构采用可快速重构的模块化方案，同一平台可适配医院药房和家庭用药两种差异化的应用场景。
3.	创新性地在边缘设备部署轻量化AI模型，同时通过MQTT协议实现云端数据同步，在保证响应速度的同时实现了多终端数据共享。
4.	结合毫米波接近感应和语音交互技术，为老年用户提供了更人性化的无接触操作体验。
1.6	设计流程
 
本项目遵循系统化的设计开发流程，从项目方案的技术定型阶段开始，工程团队首先完成核心机器架构的详细设计，并实现关键支撑结构的组装验证。随后进入硬件工程实施阶段，涵盖机械结构设计、多层PCB电路板的精密印刷与焊接工艺、机电一体化装配，以及严格的电路功能测试和系统安装方案优化。在软件层面，项目团队同步开展模块化驱动开发工作，在完成底层驱动开发后，团队构建了完整的应用层业务逻辑，同时推进云端服务架构设计，采用OneNET云平台在阿里云环境实现高可用部署。项目最终经过严格的系统级测试验证，包括功能测试、性能测试和稳定性测试，确保整体系统达到设计指标。

第二部分  系统组成及功能说明
2.1	整体介绍
 
智能药仓集成机电一体化硬件与AI技术，核心采用STM32系列处理器（H7/F407/G431）协调控制，搭载轻量化AI视觉识别模型和多模态传感器阵列，实现药品精准抓取、环境监测及用户感知。系统支持模块化药仓设计，具备智能服药提醒（语音/LED/APP推送）、药物配伍禁忌警示及触控屏交互功能，配套跨平台APP支持远程管理，通过MQTT协议与云端同步数据，满足医院药房和家庭场景的智能化药品管理需求。
2.2	硬件系统介绍
2.2.1 硬件整体介绍；
本系统以STM32H7高性能处理器作为核心运算单元，运行轻量化AI视觉识别算法实现药品智能识别。系统主控采用STM32F407微控制器，协调药仓机电控制系统，与分布式控制单元（基于STM32G431的电控板）实时交互。各执行器单元集成高精度红外对射传感器和应变式压力传感器，实现药品抓取定位和配送。
2.2.2 机械设计介绍
 机械结构设计采用30-30铝型材搭建药仓整体的骨骼框架，并在多处使用了高透或乳白色亚克力板。整个项目药品的抓取和拿放都依靠其中5个270度舵机组成的简易机械臂和XY轴步进电机驱动系统。项目实物多处使用到了M4和M6公制螺丝进行加固，并在设计到实物的过程中，普遍采用到了3D打印技术去完成本项目的实物制作需求。
	在此一体化智能药仓项目在实物搭建上，使用到了亚克力玻璃板将药仓空间划分为12个单独的储存仓室，并准备为每一个仓室适配各自的夹取药品的机械运动轨迹…实现药物精准配送。
 	 
	对于机械臂的设计，我们使用到了5个20N·cm的270度舵机，并依次连接组合成了一个5个自由度的机械抓取机构。同时，机械臂底部B轴与XY轴步进驱动系统相连，可以让整体机械臂在药仓的运动范围不受太大限制，实现药物配送任务的快速完成。详细到机械臂末端抓取机构，本团队成员使用到了舵机链接“双人字齿轮”，驱动平行对称的连杆机构，进而达到抓取药品有较平稳的夹取姿态。
在机械爪末端预留了槽位用于“红外对射传感器”和“薄膜压力传感器”的安装。它的作用是检测夹取药品时，判断当前位置是否真有药品可以用于夹取，并在夹取过程中通过压力传感器得到力度合适的舵机运动角度。
	 
本项目药仓还在实物顶部设计了“可容纳摄像头模组和触控屏”的非标机械设计，可用于后期做药品的图像采集和图像识别…从而完善整个工程从药品入库到配送这一流程链的智能和自动化的属性。
 
	在亚克力板设计上，项目也有为后期电路PCB板的安装上的思虑。团队成员为所有可能安装电路板和电线走线的地方都有一定安装余留和孔位预留。这为为后期电路搭建建立了良好的容错空间。

2.2.3 电路各模块介绍
 
本项目的电路驱动系统采用到了3块ST公司主流的MCU产品，他们分别是用于主控的STM32F407VGT6，用于做电机控制的STM32G431CBT6和可部署“STM32cube.AI工具链”用于做药仓的药品入库图像识别。其中，用于主控和图像识别的MCU，我们使用到了自绘的“洞洞板”连接各个模块的功能引脚…而对于电机控制的电控板，我们自制了完整的电路开发板，其PCB设计界面及原理图如下：
   
  
 
   
 
2.3	软件系统介绍
2.3.1 软件整体介绍（含PC端或云端，结合关键图片）；
软件上本项目采用到了GUI_Guider软件设计LVGL图形化GUI界面，完美适配STM32端单片机的屏幕软件触控交互。团队成员也同时开发了网页端和APP端的上位机控制控制软件，实现药仓万物互联…可以通过分享账号，让家人或者管理人员远程操控药仓的入库及配药。
   
2.3.2 软件各模块介绍
	上位机APP和云端代码由我们团队成员使用Vue.js和HBuilderX自主开发完成。Vue.js是一个用于构建用户界面的渐进式 JavaScript 框架,也是当前的最流行的前端开发框架之一。Vue.js的双向数据绑定机制，很好的支持了我们APP和云端网站的数据动态更新及交互。此外，我们使用HBuilderX将Vue.js代码打包成apk安装包和web包，使Vue.js代码既可在移动端应用，也可在PC端部署，丰富了项目的软件生态。
上位机APP与云端网站通过HTTP请求，以OneNet平台为媒介实现与硬件之间的通信。
 
图为APP读取硬件设备数据
 

图为APP下发命令控制硬件设备

	 APP主要页面包括：首页（导航页面）、存药页面、取药页面、药仓药品实时情况页面等。登陆页面密码固定为：123456。
 
APP结构图
可视化图表为用户提供清晰明了的药仓数据，其中涉及到的主要代码逻辑为：封装自定义组件CircleChart、从 OneNet平台获取数据、对数据进行处理、使用自定义组件CircleChart进行图表绘制。
用户可通过APP查询药仓实时情况，实现异地查询药仓药品情况，打破空间限制。用户仅需在药仓实时情况页面点击“获取药仓药品信息”按钮，即可获取最新信息。Vue.js的双向数据绑定机制支持动态更新数据，用户可以随时获取最新信息。
  
图为获取最新药品信息操作流程
我们还使用HBuilderX将uniapp项目打包成web代码，并通过宝塔面板将其部署到阿里云服务器上。使用者不仅可以下载APP，还可以通过访问我们的网站来实现对药仓的操控或查询药仓药品。虽然移动端APP使用起来十分便利。但是云端网站仍然具有不占手机内存，不限制手机操作系统（安卓和苹果均可在浏览器输入网址访问我们的网站）等优点。 

第三部分  完成情况及性能参数
阐述最终实现的成果（图文结合，实物照片为主）
3.1	 整体介绍（整个系统实物的正面、斜45°全局性照片）
 
 
3.2	 工程成果（分硬件实物、软件界面等设计结果）
3.2.1 机械成果；
 

 
3.2.2 电路成果；
  
以上为自制电控板的整体构成，以下为核心板（主控及STM32H750模型运算单元的模块连接电路设计）
 
 


 
3.2.3 软件成果；
    

   
（界面照片）
第四部分  总结
4.1	 可扩展之处
智能药仓的AI视觉识别系统可通过持续模型迭代大幅提升功能覆盖范围与精度。在药品识别方面，当前轻量化模型可支持单一药品的快速分类，未来通过引入更复杂的卷积神经网络（如ResNet改进架构）和多模态训练数据（包括药品包装的3D扫描图像、光学字符识别OCR增强的说明书文本），系统可实现对混合摆放药品的同步识别与自动分拣，显著提升药房分拣效率。进一步结合医院的电子处方系统，AI可自动核对处方药品与实际抓取的匹配度，通过比对药品数据库中的剂量、剂型及禁忌症数据，在取药环节即时警示潜在错误（如剂量超标或配伍冲突），形成闭环药品安全校验机制。
在个性化用药管理方面，系统可深度整合用户健康数据流：通过蓝牙/Wi-Fi接入智能手环、血糖仪等IoT设备，实时同步用户的生理指标（如心率、血压、血糖趋势），结合药品药效动力学模型，动态调整服药提醒策略。例如，检测到用户血压异常时，自动延迟服用降压药并推送医生咨询建议；或根据睡眠监测数据优化镇静类药物的分发时间。AI引擎还可学习用户的历史用药记录与反馈，生成用药效果评估报告，为家庭医生提供调整用药方案的参考依据。这种数据驱动的个性化服务，既能提升用药依从性，又能降低不良反应风险，实现从“被动提醒”到“主动健康干预”的升级。

4.2	心得体会
参与 “一体化智能药仓” 项目的开发，是一次将嵌入式技术、人工智能与医疗需求深度融合的实践旅程。从最初的政策解读到最终的软硬件协同运行，每一步都充满挑战，却也让我们深刻体会到 “用技术解决实际问题” 的成就感。

项目启动时，我们反复研读《“十四五” 全民健康信息化规划》中 “药品精细化管理” 的要求。这些要求让我们坚定了方向：要做一个真正 “有用” 的智能药仓，而不只是堆砌技术的展示品。

硬件开发的过程，更像一场与 “稳定性” 的博弈。机械臂的设计曾让我们纠结许久，最初为了追求速度，选用了高扭矩舵机，却发现抓取药品时容易打滑。后来在机械爪内侧增加了硅胶垫，又通过压力传感器反复测试力度 —— 这个看似简单的调整，背后是团队连续一周的调试，只为让每一次取药都稳当可靠。记得第一次看到机械臂稳稳抓起感冒灵颗粒，精准放进指定仓位时，大家都忘了疲惫，因为这意味着我们离 “减少错服风险” 的目标近了一步。

在调试软硬件交互时，我们发现无论使用APP发送多少次HTTP请求，硬件方面都未执行对应操作。我们排查了每一处技术细节，反复检验代码逻辑，在使用“Vofa串口通信”软件检查ESP8266时，发现ESP8266能正常收到信息。于是我们猜测可能是我们将ESP8266与STM32F407之间的串口连接错误了。通过检查串口连接，果然发现了错误，重新连接后，硬件端可以成功执行软件发送的指令，软硬件交互成功了！这一刻，团队付出的所有努力都有了意义。

AI 视觉识别模块的开发，让药仓有了 “看懂” 药品的能力。我们没有追求复杂的模型，而是聚焦实用性：用轻量化算法实现快速识别，确保老人存药时不用等待太久。当系统第一次准确识别出 “复方感冒灵片” 并自动关联效期提醒时，我突然意识到，技术的温度就藏在这些贴心的细节里 —— 它能让独居老人不用再对着药盒发愁，让忙碌的药师少一份核对的压力。

在上位机 APP 的开发与设计中，则教会我们要多尝试新方法。最初页面功能繁杂，开发时任务艰巨，仅在HBuilderX的内置浏览器中测试软件功能。后续将代码打包成APK安装包后进入手机实测，发现APP“存药”无法触发。为了解决这个问题，我们团队成员先打开手机的开发者模式和无线调试，将手机连接HBuilderX进行调试，反复阅读代码，并在一些可能出错的地方进行修改，积极进行尝试，虽然每一次尝试都已失败告终，但是我们告诉自己，每一次失败都排除了一种错误方法。最终定位错误为Vue中select组件与安卓系统不兼容，于是我们尝试更换了picker组件并解决了问题。

回望整个过程，技术只是手段，解决问题才是目的。智能药仓的每一个零件、每一行代码，最终都指向同一个目标：让药品管理更安全、更简单。这段经历让我明白，真正有价值的创新，从来不是炫技式的突破，而是像春雨般润物无声 —— 用技术的力量，悄悄解决那些被忽视的民生痛点，让生活多一份安心与便利。这或许就是我们作为开发者，最该坚守的初心。

