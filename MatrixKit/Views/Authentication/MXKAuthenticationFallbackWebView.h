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

@interface MXKAuthenticationFallbackWebView : UIWebView <UIWebViewDelegate>

/**
 Open authentication fallback page into the webview.
 
 @param fallbackPage the fallback page hosted by a homeserver.
 @param success the block called when the user has been successfully logged in or registered.
 */
- (void)openFallbackPage:(NSString*)fallbackPage success:(void (^)(MXLoginResponse *loginResponse))success;

@end
