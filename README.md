## QwQ2

#### 使用范围

可以用于简单的混淆, 文件不会被各种违规识别算法封禁, 如各国产网盘.

不建议应用于真正需要加密的场景, 略有密码学常识的人看了标题就知道怎么解密(解码)了.


#### Help

```markdown
usage: qwq2 --input=string [options] ... 
  (qwq2-v0.2.0-win64)
options:
  -i, --input     input file (string)
  -o, --output    output file (string [=])
  -k, --key       key (string [=])
  -?, --help      print this message
```

### Clone

```sh
git clone --recurse-submodules --remote-submodule https://github.com/userElaina/naive-confuse.git
```

### License

The code is available under the [MIT license](./LICENSE).

### Windows

```sh
clang++ "qwq2.cpp" -o "qwq2.exe" -w -g -O3 -static-libgcc --target=x86_64-w64-mingw
./qwq2 --help
```

or

```sh
g++ "qwq2.cpp" -o "qwq2.exe" -w -g -O3 -static-libgcc
./qwq2 --help
```

### Linux

```sh
g++ "qwq2.cpp" -o "qwq2.out" -w -g -O3 -static-libgcc
chmod +x ./qwq2.out
./qwq2.out --help
```
