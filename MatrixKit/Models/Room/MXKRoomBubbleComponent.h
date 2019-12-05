/*
 Copyright 2015 OpenMarket Ltd
 
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at
 
 http://www.apache.org/licenses/LICENSE-2.0
 
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */

#import <SwiftMatrixSDK/MatrixSDK.h>

#import "MXKEventFormatter.h"

/**
 Flags to indicate if a fix is required at the display time.
 */
typedef enum : NSUInteger {

    /**
     No fix required.
     */
    MXKRoomBubbleComponentDisplayFixNone = 0,

    /**
     Borders for HTML blockquotes need to be fixed.
     */
    MXKRoomBubbleComponentDisplayFixHtmlBlockquote = 0x1

} MXKRoomBubbleComponentDisplayFix;

/**
 `MXKRoomBubbleComponent` class compose data related to one `MXEvent` instance.
 */
@interface MXKRoomBubbleComponent : NSObject

/**
 The body of the message, or kind of content description in case of attachment (e.g. "image attachment").
 */
@property (nonatomic) NSString *textMessage;

/**
 The `textMessage` with sets of attributes.
 */
@property (nonatomic) NSAttributedString *attributedTextMessage;

/**
 The event date
 */
@property (nonatomic) NSDate *date;

/**
 Event formatter
 */
@property (nonatomic) MXKEventFormatter *eventFormatter;

/**
 The event on which the composent is based (used in case of redaction)
 */
@property (nonatomic, readonly) MXEvent *event;

// The following properties are defined to store information on component.
// They must be handled by the object which creates the MXKRoomBubbleComponent instance.
//@property (nonatomic) CGFloat height;
@property (nonatomic) CGPoint position;

/**
 Set of flags indicating fixes that need to be applied at display time.
 */
@property (nonatomic) MXKRoomBubbleComponentDisplayFix displayFix;

/**
 Event antivirus scan. Present only if antivirus is enabled and event contains media.
 */
@property (nonatomic) MXEventScan *eventScan;

/**
 Create a new `MXKRoomBubbleComponent` object based on a `MXEvent` instance.
 
 @param event the event used to compose the bubble component.
 @param roomState the room state when the event occured.
 @param eventFormatter object used to format event into displayable string.
 @return the newly created instance.
 */
- (instancetype)initWithEvent:(MXEvent*)event andRoomState:(MXRoomState*)roomState andEventFormatter:(MXKEventFormatter*)eventFormatter;

/**
 Update the event because its sent state changed or it is has been redacted.

 @param event the new event data.
 @param roomState the up-to-date state of the room.
 */
- (void)updateWithEvent:(MXEvent*)event andRoomState:(MXRoomState*)roomState;

@end

