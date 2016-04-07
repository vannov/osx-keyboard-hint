# osx-keyboard-hint
This is a Qt based "keyboard hint" application. I made this app to help myself learning "touch typing", i.e. typing text without looking at the keyboard.

![Alt text](http://s14.postimg.org/hfnbgvuxt/Screen_Shot_2016_04_06_at_20_17_42.png "Keyboard Hint screenshot")

The app consists of a single window with a keyboard layout. Keys are colored by groups, each group corresponds to a finger that one would use to press a key. While running the window always stays on top of other opened windows.

The is a top idea is to keep this app always opened on top of other apps, to use it as a hint while typing text. Thus one can use it to check which finger should be used to press certain key.

The keyboard layout is loaded from json file: /resources/keyboard_layout.json. By editing this json file you can add and modify groups, colors, rows of keys, special keys characters etc.

The app reacts on key events while it's in focus. It will highlight pressed keys, change layout to upper case when Shift is pressed etc. But this doesn't work when the focus is acquired by another application, currenly system-wide detection of key events is not implemented.

I added recongition of current system input language is OS X, so the app will switch layout to different language if this language is configured in keyboard_layout.json. For now I only added English (default) and Russian layouts.

I compiled and tested the app only on OS X 10.11, but it could be easily ported to other platforms since it's Qt based. Repositiry contains 'keyboard.pro' project file for Qt Creator IDE.