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

#import "MXKTableViewCell.h"

/**
 MKPushRuleTableViewCell instance is a table view cell used to display a notification rule.
 */
@interface MXKPushRuleTableViewCell : MXKTableViewCell

/**
 The displayed rule
 */
@property (nonatomic) MXPushRule* mxPushRule;

/**
 The related matrix session
 */
@property (nonatomic) MXSession* mxSession;

/**
 The graphics items
 */
@property (strong, nonatomic) IBOutlet UIButton* controlButton;

@property (strong, nonatomic) IBOutlet UIButton* deleteButton;
@property (unsafe_unretained, nonatomic) IBOutlet NSLayoutConstraint *deleteButtonWidthConstraint;

@property (strong, nonatomic) IBOutlet UILabel* ruleDescription;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *ruleDescriptionBottomConstraint;
@property (unsafe_unretained, nonatomic) IBOutlet NSLayoutConstraint *ruleDescriptionLeftConstraint;


@property (strong, nonatomic) IBOutlet UILabel* ruleActions;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *ruleActionsHeightConstraint;

/**
 Action registered on `UIControlEventTouchUpInside` event for both buttons.
 */
- (IBAction)onButtonPressed:(id)sender;

@end
