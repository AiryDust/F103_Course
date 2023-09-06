GPIO输入。

步骤：
	1、新建bsp板级支持文件及头文件，并关联。
	2、C文件中定义初始化函数，需要初始化时钟以及GPIOB的两个端口的结构体，设置为浮空输入（其它亦可）。
	3、C文件中定义读取函数，GPIO_ReadInputDataBit。
	4、在h文件中拉取所有相关引脚、端口等，确保可移植性：换板只用调整h文件定义即可。

特别注意：
	初始化结构体时注意避免野指针现象，尽量使用&parm将变量地址送库函数，避免定义parm为指针。
	GPIO_Init(KEY_2_Port, &KEY_GPIO_InitStruct);
	而非使用：
	GPIO_Init(KEY_2_Port, KEY_GPIO_InitStruct);