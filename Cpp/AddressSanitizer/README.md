# 编译选项：
- -fsanitize=address : 启用address sanitize
- -fno-omit-frame-pointer : 留下栈指针，使能更快解析堆栈
- -fsanitize-blacklist=path ： 黑名单路径
- -fno-common ： 不把C语言中的全局变量当成普通变量



# 常用环境变量：
- log_path="" : 输出日志路径
- halt_on_error=true|false : 让进程在遇到第一个错误时carsh。该变量仅启动了-fsanitize-recover=address时生效
- detect_stack_use_after_return=true|false : 启动，禁用 stack_use_after_return

## 方法
```shell
$ export
ASAN_OPTIONS=log_path="asan.txt":halt_on_error=false:detect_stack_use_after_return=false
```



