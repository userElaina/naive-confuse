# QwQ2
---
快速入门(Quick Start)
---
加密:将想要加密的文件用鼠标按着拖放到 `qwq2.exe` 上,生成一个加密好的后缀为 `.qwq2` 的文件.

解密:将想要解密的文件用鼠标按着拖放到 `qwq2.exe` 上,生成一个解密好的后缀去掉了 `.qwq2` 的文件.

Encode: Drag and drop the file you want to encode onto my program `qwq2.exe`, and then an encoded file will be created with `.qwq2` extension.

Encode: Drag and drop the file you want to decode onto my program `qwq2.exe`, and then an decoded file will be created without `.qwq2` extension.

[Download](https://github.com/userElaina/naive-confuse/releases/download/0.0.3/qwq2.exe)

---
使用范围
---
可以用于简单的混淆,文件不会被各种违规识别算法封禁(手动@百度网盘).

不建议应用于真正需要加密的场景,略有密码学常识的人看了标题就知道怎么解密了(其实只能算是解码).

对于那种使用百度网盘在线解(封)压(禁)功能的人来说,这个程序的算法跟国密系列差不了多少(所以别™在线解压).

---
命令行工具
---
```
parameters:

    	[INPUT_FILE_ADDRESS]
		INPUT_FILE_ADDRESS will be encoded (or decode).
    		This parameter is necessary. It should be given first.
	
	-o [OUTPUT_FILE_ADDRESS]
		OUTPUT_FILE_ADDRESS will be *.qwq by default where * is INPUT_FILE_ADDRESS.
		This parameter is not necessary.
	
	-p [PASSWORD]
		Encode with PASSWORD
    		This parameter is not necessary and should be given last.
	
    	You can use it like this:
    		qwq2 /root/c/qwq/2/tf/1.zip -o /root/c/qwq/2/tf/mima123456.qwq2 -p 123456
```
Or you can use `qwq2 -h` to get help.
      
