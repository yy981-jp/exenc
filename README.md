# [日本語]
exenc <対象Dir> <対象拡張子> <_CMD_> [CMD] ...
CMDはスペースを入れてから全て結合され、一つのコマンドとみなします

下はpngファイルの名前を一括で変えるコマンド例
``` cpp
C:\images .png rename IFILE 新INAME.png
```
ターゲットになったファイルが、c:\images\2009\8\1.pngだった時、
```
IFILE -> c:\images\2009\8\1.png
IDIR -> c:\images\2009\8
INAME -> 1
```
に置き換えられます

# [English]
exenc <target_Dir> <target_extension> <_CMD_> [CMD] ...
CMDs are all combined after a space and considered as one command 

Below is an example command to rename png files in bulk 
``` cpp 
C:\images .png rename IFILE new_INAME.png 
``` 
When the target file was c:\images\2009\8\1.png, it will be replaced by 
``` 
IFILE -> c:\images\2009\8\1.png 
IDIR -> c:\images\2009\8 
INAME -> 1 
```

Translated with DeepL
