var Globals = {
    BUTTON_DEFAULT_SIZE: 25,
    GRID_SPACING: 3
}

var LayoutHelper = {
    layoutGroups: {},
    layoutRows: [],
    currentLang: "",

    InitLayout: function() {
        var jsonStr = keyboardHelper.getJsonKeyboard();
        this.currentLang = keyboardHelper.getKeyboardLanguage();
        console.log("keyboardLang: ", this.currentLang);
        var layout;
        if (jsonStr) {
            layout = JSON.parse(jsonStr);
        }
//        else {
//            layout = defaultLayout;
//        }
        this.layoutGroups = layout["Groups"];
        this.layoutRows = layout["Rows"];
        //console.log("layoutGroups", JSON.stringify(layoutGroups));
        this.createButtons();        
        this.changeLanguage(this.currentLang);
    },

    getColorByGroupID: function(groupID) {
        if (this.layoutGroups[groupID])
            return this.layoutGroups[groupID]["color"];
        else
            return defaultButtonColor;
    },

    createButtons: function() {
        var maxWidth = 0, totalWidth = 0, totalHeight = 0;
        for(var rIndex = 0; rIndex < this.layoutRows.length; ++rIndex) {
            var rComponent = Qt.createComponent("ButtonsRow.qml")
            rComponent.createObject(grid);
            for(var bIndex = 0; bIndex < this.layoutRows[rIndex]["buttons"].length; ++bIndex) {
                var buttonInfo = this.layoutRows[rIndex]["buttons"][bIndex];
                var bComponent = Qt.createComponent("KeyButton.qml");
                var bW = 1, bH = 1; // 1 - default size value
                if (buttonInfo["size"]) {
                    bW = buttonInfo["size"]["w"];
                    bH = buttonInfo["size"]["h"];
                    //console.log("bW", bW);
                    //console.log("bH", bH);
                }
                bComponent.createObject(grid.children[rIndex],
                                                 {
                                                   "default_text": buttonInfo["text"],
                                                   "shifted_text": buttonInfo["shifted"],
                                                   "color": this.getColorByGroupID(buttonInfo["group"]),
                                                   "code": parseInt(buttonInfo["code"]),
                                                   "lang": buttonInfo["lang"],
                                                   "bump": buttonInfo["bump"],
                                                   "w": bW,
                                                   "h": bH
                                                  });
                totalWidth += bW * Globals.BUTTON_DEFAULT_SIZE + Globals.GRID_SPACING;
                //ButtonHelper.changeLanguage(grid.children[rIndex], this.currentLang);
            }
            totalWidth -= Globals.GRID_SPACING;
            if (totalWidth > maxWidth)
                maxWidth = totalWidth;
            totalWidth = 0;

            totalHeight += Globals.BUTTON_DEFAULT_SIZE + Globals.GRID_SPACING;
        }
        window.width = maxWidth;
        totalHeight -= Globals.GRID_SPACING;
        window.height = totalHeight;
        console.log("maxWidth: ", maxWidth, "maxHeight", totalHeight);
        window.initial_width = maxWidth;
        window.loaded = true;
    },

    changeCase: function(upper) {
        for (var i = 0; i < grid.children.length; ++i) {
            var row = grid.children[i];
            for(var j = 0; j < row.children.length; ++j) {
                if (upper)
                    ButtonHelper.toUpper(row.children[j]);
                else
                    ButtonHelper.toLower(row.children[j]);
            }
        }
    },

    highLightKey: function(code, turnOn) {
        for (var i = 0; i < grid.children.length; ++i) {
            var row = grid.children[i];
            for(var j = 0; j < row.children.length; ++j) {
                if (code == row.children[j].code)
                    ButtonHelper.highLight(row.children[j], turnOn);
            }
        }
    },

    changeLanguage: function(newLang) {
        for (var i = 0; i < grid.children.length; ++i) {
            var row = grid.children[i];
            for(var j = 0; j < row.children.length; ++j) {
                ButtonHelper.changeLanguage(row.children[j], newLang);
            }
        }
    }
}

var EventHelper = {
    capsLockOn: false,
    onKeyEvent: function(event, pressed) {
        //console.log("event:", JSON.stringify(event));
        LayoutHelper.highLightKey(event.key, pressed);

        if (event.key == Qt.Key_Shift) {
            var flag = this.capsLockOn ? !pressed : pressed;
            LayoutHelper.changeCase(flag);
        }
        else if (event.key == Qt.Key_CapsLock) {
            this.capsLockOn = !this.capsLockOn;
            LayoutHelper.changeCase(this.capsLockOn);
        }

        // Update current language on key release. Ugly solution to track language change
        // TODO: implement language change event handling
        if (!pressed) {
            var newLang = keyboardHelper.getKeyboardLanguage();
            if (LayoutHelper.currentLang != newLang) {
                console.log("change lang: ", LayoutHelper.currentLang);
                LayoutHelper.currentLang = newLang;
                LayoutHelper.changeLanguage(LayoutHelper.currentLang);
            }

        }
    }
}

var ButtonHelper = {
    toUpper: function(btn) {
        if (btn.shifted_text) {
            btn.text = btn.shifted_text
        }
        btn.text = btn.text.toUpperCase()
    },
    toLower: function(btn) {
        if (btn.shifted_text) {
            btn.text = btn.default_text
        }
        btn.text = btn.text.toLowerCase()
    },
    highLight: function(btn, turnOn) { btn.active = turnOn },
    changeLanguage: function(btn, newLang) {
        if (btn.lang && btn.lang[newLang]) {
            btn.text = btn.lang[newLang]["text"];
        }
        else {
            btn.text = btn.default_text;
        }
    }
}
