#!/bin/sh

set -e
set -x

DATA_DIR=/tmp/deriveddata
OUTPUT_DIR=/tmp/xcf
SDK=MatrixKit
SCHEME=MatrixKit

rm -rf Pods Podfile.lock $SDK.xcworkspace
rm -rf $OUTPUT_DIR
rm -rf $DATA_DIR

pod install

build() {
    xcodebuild $1 \
        -workspace "$SDK.xcworkspace" \
        -scheme "$SCHEME" \
        -archivePath "$OUTPUT_DIR/$2" \
        -derivedDataPath "$DATA_DIR" \
        -sdk "$3" \
        SKIP_INSTALL=NO \
        BUILD_LIBRARIES_FOR_DISTRIBUTION=YES
}

build build \
      ios.xcarchive \
      iphoneos \

build build \
      iossimulator.xcarchive \
      iphonesimulator \

xcodebuild -create-xcframework \
           -framework $DATA_DIR/Build/Products/Debug-iphoneos/$SDK.framework \
           -framework $DATA_DIR/Build/Products/Debug-iphonesimulator/$SDK.framework \
           -output $OUTPUT_DIR/$SDK.xcframework
