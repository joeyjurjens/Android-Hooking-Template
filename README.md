# Android Hooking Template
This is a simple template for the usage of Cydia Substrate.

### Installation:
* Download Android NDK, Revision 16b from: https://developer.android.com/ndk/downloads/older_releases
* Open compile.bat & paste your ndk-build path location in the first line. (remove mine)
* Download this github files somewhere to your PC.

<br>

### Creating the libhook.so
I'm not going to explain how Cydia Substrate works, since it has it's own documentation.
* Inside the file "<b>Utils.h</b>", you'll specifiy the lib name of the game.
* Inside "<b>hook.cpp</b>", you'll write your hooks.
* Once done, double click <b>compile.bat</b> & it will create a libs folder.
* Inside the libs folder, you'll have a "<b>libhook.so</b>" file, this will be placed inside the APK's lib folder.

<br>

### Loading the lib.so
In order to load your <b>libhook.so</b>, you'll need to decompile the apk, you can use ApkTool for this.
* Navigate to "<b>/smali/com</b>" & create a folder called "<b>loadLib</b>"
* Copy the two .smali files provided in the smali folder from this Git, inside of that folder.
* Now, navigate to "<b>com/unity3d/player/UnityPlayerActivity</b>" & search for something like this:

```java
.method protected onCreate(Landroid/os/Bundle;)V
    .locals 2
```

* Once found, paste this code under .locals 2:

```java
invoke-static {}, Lcom/loadLib/libLoader;->loadLib()V
```
* Recompile the apk & test out your hack!


<br>

### Useful links
<b>Cydia Substrate Documentation</b>: http://www.cydiasubstrate.com/id/264d6581-a762-4343-9605-729ef12ff0af/
