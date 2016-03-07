Lab1 实现
=========
stmr函数通过传参的方式将变量压栈，然后在函数体内再将参数读进寄存器a，并通过TIME设置timeout。每次执行指令timer会加delta，每次timeout会产生中断，并调用用ivec设置的函数alltraps使计数器current增加1，每100次中断会在循环体里输出“100 ticks”并将current置0。
