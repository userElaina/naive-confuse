# QwQ2
---
快速入门
---
加密:将想要加密的文件拖放到 `qwq2.exe` 上,生成一个加密好的后缀为 `.qwq2` 的文件.

解密:将想要解密的文件拖放到 `qwq2.exe` 上,生成一个解密好的后缀去掉了 `.qwq2` 的文件.

由于算法的对称性,有一个我懒得修复的 `BUG`: 无论是加密还是解密,程序中输出的动词都是 `decode`. 这不影响正常使用.

[下载地址](https://github.com/userElaina/naive-confuse/releases/download/0.0.3/qwq2.exe)

---
Quick Start
---
Encode: Drag and drop the file you want to encode onto my program `qwq2.exe`, and then an encoded file will be created with `.qwq2` extension.

Encode: Drag and drop the file you want to decode onto my program `qwq2.exe`, and then an decoded file will be created without `.qwq2` extension.

Because of the symmetry of the algorithm, there is a BUG that I don't want to fix. The verb output in the program is `decode`, both for encoding and decoding. This does not affect normal usage.

[Download](https://github.com/userElaina/naive-confuse/releases/download/0.0.3/qwq2.exe)

---
使用范围
---
可以用于简单的混淆,文件不会被各种违规识别算法封禁(手动@百度网盘).

不建议应用于真正需要加密的场景,略有密码学常识的人看了标题就知道怎么解密了(其实只能算是解码).

对于那种使用百度网盘在线解(封)压(禁)功能的人来说,这个程序的加密程度跟国密系列差不多.

---
命令行工具
---
```cpp
		"\nqwq2 xor encoder helper\n\n"
    	"[INPUT_FILE_ADDRESS]\n    INPUT_FILE_ADDRESS will be encoded (or decode).\n"
    	"This parameter is necessary. It should be given first.\n\n"
		"-o [OUTPUT_FILE_ADDRESS]\n    OUTPUT_FILE_ADDRESS will be *.qwq by default where * is INPUT_FILE_ADDRESS.\n"
    	"This parameter is not necessary.\n\n"
		"-p [PASSWORD]\n    Encode with PASSWORD.\n"
		"-f [PASSWORD_FILE_ADDRESS]\n    Code with the file PASSWORD_FILE_ADDRESS.\n"
    	"There should be only one of these two parameters. They are not necessary and should be given last.\n\n"
    	"You can use it like this:\n"
    	"    qwq2 /root/c/1.txt -o /root/c/1.out -p 123456\n\n"
    	"Warning:\n"
    	"If the output address exists in a file, it will disappear forever.\n\n"
    	"Or you can read README.md to get help.\n\n"
```
      
