//
//  LCIMKeyedConversation.h
//  LeanCloud
//
//  Created by Tang Tianyong on 6/12/15.
//  Copyright (c) 2015 LeanCloud Inc. All rights reserved.
//

#import "LCIMCommon.h"

@class LCIMMessage;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Represents a conversation which intends to be archived. Can get this object from LCIMConversation by -[LCIMConversation keyedConversation]. Can convert this object to LCIMConverstaion by -[LCIMClient conversationWithKeyedConversation:].
 */
@interface LCIMKeyedConversation : NSObject <NSCoding>

@property (nonatomic, copy,   readonly, nullable) NSString     *conversationId; // 对话 id
@property (nonatomic, copy,   readonly, nullable) NSString     *creator;        // 创建者 id
@property (nonatomic, strong, readonly, nullable) NSDate       *createAt;       // 创建时间
@property (nonatomic, strong, readonly, nullable) NSDate       *updateAt;       // 最后更新时间
@property (nonatomic, strong, readonly, nullable) NSDate       *lastMessageAt;  // 对话中最后一条消息的发送时间
@property (nonatomic, strong, readonly, nullable) NSDate       *lastDeliveredAt; // 对话中最近的、消息抵达对方设备的回执时间
@property (nonatomic, strong, readonly, nullable) NSDate       *lastReadAt;      // 对话中最近的、消息被接收方标记为已读的时间
@property (nonatomic, strong, readonly, nullable) LCIMMessage  *lastMessage;    // 对话中最后一条消息
@property (nonatomic, copy,   readonly, nullable) NSString     *name;           // 对话名字
@property (nonatomic, strong, readonly, nullable) NSArray      *members;        // 对话参与者列表
@property (nonatomic, strong, readonly, nullable) NSDictionary *attributes;     // 自定义属性

@property (nonatomic, strong, readonly, nullable) NSString *uniqueId;

@property (nonatomic, assign, readonly) BOOL    unique;
@property (nonatomic, assign, readonly) BOOL    transient;
@property (nonatomic, assign, readonly) BOOL    system;
@property (nonatomic, assign, readonly) BOOL    temporary;
@property (nonatomic, assign, readonly) NSUInteger temporaryTTL;
@property (nonatomic, assign, readonly) BOOL    muted;

@end

NS_ASSUME_NONNULL_END
