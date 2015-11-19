# Credit-Cards-Reader-Cordova-Phonegap-Plugin
Phonegap\Cordova Credit cards reader plugin with the IMagPay Device for Mobile Phones

example of the device: http://img2.en.china.cn/0/2_849_30052_502_337.jpg

DOCS:

To listen for cards swipe, go to your cordova project > www > js > index.js and add the following code:

CardReader.Read(success, fail);

function success(cardNum, expDate, cardHolder) {
    console.log(cardNum, expDate, cardHolder);
}

function fail(error) {
    console.log(error);
}

In order for the plugin to work, you must add\set the following settings for each platforms:

android
add audio permission. in your project platforms > android > open androidManifest.xml and add this:
<uses-permission android:name="android.permission.RECORD_AUDIO" />

IOS - in your project's target && project:
disable bit code

make sure in other linker flags there is $(inherited) 

valid architectures in project && target: arm64.

build active architectures only in your target && project: yes.
in CordovaLib.xcodeproj set to build active architectures only to no.

architectures: click on other and remove first line and add armv7 and armv7s. afterwards click again and change to standard architectures



Plugin 'CardReader' not found, or is not a CDVPlugin. Check your plugin mapping in config.xml.

in plugin > DBLCard.m check target Membership checkbox.

go to Staging > config.xml and add the following feature:
<feature name="CardReader">
            <param name="ios-package" value="DBLCard" />
        </feature>
        
The plugin is currently in beta tests.
