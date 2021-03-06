//
//  LCCaptcha.h
//  LeanCloud
//
//  Created by Tang Tianyong on 03/05/2017.
//  Copyright © 2017 LeanCloud Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LCDynamicObject.h"

NS_ASSUME_NONNULL_BEGIN

@interface LCCaptchaDigest : LCDynamicObject

/**
 A nonce used to verify captcha.
 */
@property (nonatomic, copy, readonly) NSString *nonce;

/**
 URL string of captcha image.
 */
@property (nonatomic, copy, readonly) NSString *URLString;

@end

@interface LCCaptchaRequestOptions : LCDynamicObject

/**
 Width of captcha image, in pixels.

 Defaults to 85. Minimum is 85, maximum is 200.
 */
@property (nonatomic, assign) NSInteger width;

/**
 Height of captcha image, in pixels.

 Defaults to 30. Minimum is 30, maximum is 100.
 */
@property (nonatomic, assign) NSInteger height;

@end

typedef void(^LCCaptchaRequestCallback)(LCCaptchaDigest * _Nullable captchaDigest, NSError * _Nullable error);
typedef void(^LCCaptchaVerificationCallback)(NSString * _Nullable validationToken, NSError * _Nullable error);

@interface LCCaptcha : NSObject

/**
 Request a captcha.

 This method get a captcha digest from server.
 You can use the captcha digest to verify a captcha code that recognized by user.

 @param options  The options that configure the captcha.
 @param callback The callback of request.
 */
+ (void)requestCaptchaWithOptions:(nullable LCCaptchaRequestOptions *)options
                         callback:(LCCaptchaRequestCallback)callback;

/**
 Verify a captcha code for captcha digest that you've requested before.

 @param captchaCode   The symbols user recognized from captcha image.
 @param captchaDigest The captcha digest that you've requested before.
 @param callback      The callback of request.
 */
+ (void)verifyCaptchaCode:(NSString *)captchaCode
         forCaptchaDigest:(LCCaptchaDigest *)captchaDigest
                 callback:(LCCaptchaVerificationCallback)callback;

@end

NS_ASSUME_NONNULL_END
