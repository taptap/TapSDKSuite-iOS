//
//  LCPush.h
//  LeanCloud
//

#import <Foundation/Foundation.h>
#import "LCQuery.h"

NS_ASSUME_NONNULL_BEGIN

extern NSString *const kLCPushTargetPlatformIOS;
extern NSString *const kLCPushTargetPlatformAndroid;
extern NSString *const kLCPushTargetPlatformWindowsPhone;

/*!
 A class which defines a push notification that can be sent from
 a client device.

 The preferred way of modifying or retrieving channel subscriptions is to use
 the LCInstallation class, instead of the class methods in LCPush.

 This class is currently for iOS only. LeanCloud does not handle Push Notifications
 to LeanCloud applications running on OS X. Push Notifications can be sent from OS X
 applications via Cloud Code or the REST API to push-enabled devices (e.g. iOS
 or Android).
 */
@interface LCPush : NSObject

/*! @name Creating a Push Notification */

/**
 *  创建一个 LCPush 对象
 *  @return LCPush 对象
 */
+ (instancetype)push;
/**
 *  Set call what production mode's cloud code
 *
 *  @param isProduction the production mode or test mode
 */
+ (void)setProductionMode:(BOOL)isProduction;

/**
 Default is false, if set true, LCPush will remove 'prod' Key-Value.

 @param isIgnoreProd trigger.
 */
+ (void)setIgnoreProdParameterEnabled:(BOOL)isIgnoreProd;

/*! @name Configuring a Push Notification */

/*!
 Sets the channel on which this push notification will be sent.
 @param channel The channel to set for this push. The channel name must start
 with a letter and contain only letters, numbers, dashes, and underscores.
 */
- (void)setChannel:(NSString *)channel;

/*!
 Sets the array of channels on which this push notification will
 be sent.
 @param channels The array of channels to set for this push. Each channel name
 must start with a letter and contain only letters, numbers, dashes, and underscores.
 */
- (void)setChannels:(NSArray *)channels;

/*!
 Sets an installation query to which this push notification will be sent. The
 query should be created via [LCInstallation query] and should not specify a
 skip, limit, or order.
 @param query The installation query to set for this push.
 */
- (void)setQuery:(LCQuery *)query;

/*!
 Sets an alert message for this push notification. This will overwrite
 any data specified in setData.
 @param message The message to send in this push.
 */
- (void)setMessage:(NSString *)message;

/*!
 Sets an arbitrary data payload for this push notification. See the guide
 for information about the dictionary structure. This will overwrite any
 data specified in setMessage.
 @param data The data to send in this push.
 */
- (void)setData:(NSDictionary *)data;

/**
 *  Sets push target platforms.
 *
 *  @param platforms Target platforms.
 *         Value maybe in kLCPushTargetPlatformIOS,kLCPushTargetPlatformAndroid,kLCPushTargetPlatformWindowsPhone
 */
- (void)setPushToTargetPlatforms:(NSArray *)platforms;

/**
 *  Sets whether this push will go to Android devices.
 *
 *  @param pushToAndroid Defaults to true.
 */
- (void)setPushToAndroid:(BOOL)pushToAndroid;

/**
 *  Sets whether this push will go to iOS devices
 *
 *  @param pushToIOS  Defaults to true
 */
- (void)setPushToIOS:(BOOL)pushToIOS;

/**
 *  Sets whether this push will go to WinPhone devices.
 *
 *  @param pushToWP Defaults to true.
 */
- (void)setPushToWP:(BOOL)pushToWP;

/**
 *  Sets to push at sometime 
 *
 *  @param dateToPush   Defaults is now.
 */
- (void)setPushDate:(NSDate *)dateToPush;


/*!
 Sets the expiration time for this notification. The notification will be
 sent to devices which are either online at the time the notification
 is sent, or which come online before the expiration time is reached.
 Because device clocks are not guaranteed to be accurate, most applications
 should instead use expireAfterTimeInterval.
 @param date The time at which the notification should expire.
 */
- (void)expireAtDate:(NSDate *)date;

/*!
 Sets the time interval after which this notification should expire.
 This notification will be sent to devices which are either online at
 the time the notification is sent, or which come online within the given
 time interval of the notification being received by LeanCloud server.
 An interval which is less than or equal to zero indicates that the
 message should only be sent to devices which are currently online.
 @param timeInterval The interval after which the notification should expire.
 */
- (void)expireAfterTimeInterval:(NSTimeInterval)timeInterval;

/*!
 Clears both expiration values, indicating that the notification should
 never expire.
 */
- (void)clearExpiration;

/*! @name Sending Push Notifications */

/*!
 Send a push message to a channel.
 @param channel The channel to send to. The channel name must start with
 a letter and contain only letters, numbers, dashes, and underscores.
 @param message The message to send.
 @param error Pointer to an NSError that will be set if necessary.
 @return whether the send succeeded.
 */
+ (BOOL)sendPushMessageToChannel:(NSString *)channel
                     withMessage:(NSString *)message
                           error:(NSError **)error;

/*!
 Asynchronously send a push message to a channel.
 @param channel The channel to send to. The channel name must start with
 a letter and contain only letters, numbers, dashes, and underscores.
 @param message The message to send.
 */
+ (void)sendPushMessageToChannelInBackground:(NSString *)channel
                                 withMessage:(NSString *)message;

/*!
 Asynchronously sends a push message to a channel and calls the given block.
 @param channel The channel to send to. The channel name must start with
 a letter and contain only letters, numbers, dashes, and underscores.
 @param message The message to send.
 @param block The block to execute. The block should have the following argument signature: (BOOL succeeded, NSError *error) 
 */
+ (void)sendPushMessageToChannelInBackground:(NSString *)channel
                                 withMessage:(NSString *)message
                                       block:(LCBooleanResultBlock)block;

/*!
 Send a push message to a query.
 @param query The query to send to. The query must be a LCInstallation query
 created with [LCInstallation query].
 @param message The message to send.
 @param error Pointer to an NSError that will be set if necessary.
 @return whether the send succeeded.
 */
+ (BOOL)sendPushMessageToQuery:(LCQuery *)query
                   withMessage:(NSString *)message
                         error:(NSError **)error;

/*!
 Asynchronously send a push message to a query.
 @param query The query to send to. The query must be a LCInstallation query
 created with [LCInstallation query].
 @param message The message to send.
 */
+ (void)sendPushMessageToQueryInBackground:(LCQuery *)query
                               withMessage:(NSString *)message;

/*!
 Asynchronously sends a push message to a query and calls the given block.
 @param query The query to send to. The query must be a LCInstallation query
 created with [LCInstallation query].
 @param message The message to send.
 @param block The block to execute. The block should have the following argument signature: (BOOL succeeded, NSError *error)
 */
+ (void)sendPushMessageToQueryInBackground:(LCQuery *)query
                               withMessage:(NSString *)message
                                     block:(LCBooleanResultBlock)block;

/*!
 Send this push message.
 @param error Pointer to an NSError that will be set if necessary.
 @return whether the send succeeded.
 */
- (BOOL)sendPush:(NSError **)error;

/*!
 An alias of `-[LCPush sendPush:]` methods that supports Swift exception.
 @seealso `-[LCPush sendPush:]`
 */
- (BOOL)sendPushAndThrowsWithError:(NSError **)error;

/*!
 Asynchronously send this push message.
 */
- (void)sendPushInBackground;

/*!
 Asynchronously send this push message and executes the given callback block.
 @param block The block to execute. The block should have the following argument signature: (BOOL succeeded, NSError *error) 
 */
- (void)sendPushInBackgroundWithBlock:(LCBooleanResultBlock)block;

/*!
 Send a push message with arbitrary data to a channel. See the guide for information about the dictionary structure.
 @param channel The channel to send to. The channel name must start with
 a letter and contain only letters, numbers, dashes, and underscores.
 @param data The data to send.
 @param error Pointer to an NSError that will be set if necessary.
 @return whether the send succeeded.
 */
+ (BOOL)sendPushDataToChannel:(NSString *)channel
                     withData:(NSDictionary *)data
                        error:(NSError **)error;

/*!
 Asynchronously send a push message with arbitrary data to a channel. See the guide for information about the dictionary structure.
 @param channel The channel to send to. The channel name must start with
 a letter and contain only letters, numbers, dashes, and underscores.
 @param data The data to send.
 */
+ (void)sendPushDataToChannelInBackground:(NSString *)channel
                                 withData:(NSDictionary *)data;

/*!
 Asynchronously sends a push message with arbitrary data to a channel and calls the given block. See the guide for information about the dictionary structure.
 @param channel The channel to send to. The channel name must start with
 a letter and contain only letters, numbers, dashes, and underscores.
 @param data The data to send.
 @param block The block to execute. The block should have the following argument signature: (BOOL succeeded, NSError *error) 
 */
+ (void)sendPushDataToChannelInBackground:(NSString *)channel
                                 withData:(NSDictionary *)data
                                    block:(LCBooleanResultBlock)block;

/*!
 Send a push message with arbitrary data to a query. See the guide for information about the dictionary structure.
 @param query The query to send to. The query must be a LCInstallation query
 created with [LCInstallation query].
 @param data The data to send.
 @param error Pointer to an NSError that will be set if necessary.
 @return whether the send succeeded.
 */
+ (BOOL)sendPushDataToQuery:(LCQuery *)query
                   withData:(NSDictionary *)data
                      error:(NSError **)error;

/*!
 Asynchronously send a push message with arbitrary data to a query. See the guide for information about the dictionary structure.
 @param query The query to send to. The query must be a LCInstallation query
 created with [LCInstallation query].
 @param data The data to send.
 */
+ (void)sendPushDataToQueryInBackground:(LCQuery *)query
                               withData:(NSDictionary *)data;

/*!
 Asynchronously sends a push message with arbitrary data to a query and calls the given block. See the guide for information about the dictionary structure.
 @param query The query to send to. The query must be a LCInstallation query
 created with [LCInstallation query].
 @param data The data to send.
 @param block The block to execute. The block should have the following argument signature: (BOOL succeeded, NSError *error)
 */
+ (void)sendPushDataToQueryInBackground:(LCQuery *)query
                               withData:(NSDictionary *)data
                                  block:(LCBooleanResultBlock)block;

/*! @name Handling Notifications */

/*!
 Get all the channels that this device is subscribed to.
 @param error Pointer to an NSError that will be set if necessary.
 @return an NSSet containing all the channel names this device is subscribed to.
 */
+ (nullable NSSet *)getSubscribedChannels:(NSError **)error;

/*!
 An alias of `-[LCPush getSubscribedChannels:]` methods that supports Swift exception.
 @seealso `-[LCPush getSubscribedChannels:]`
 */
+ (nullable NSSet *)getSubscribedChannelsAndThrowsWithError:(NSError **)error;

/*!
 Get all the channels that this device is subscribed to.
 @param block The block to execute. The block should have the following argument signature: (NSSet *channels, NSError *error) 
 */
+ (void)getSubscribedChannelsInBackgroundWithBlock:(LCSetResultBlock)block;

/*!
 Subscribes the device to a channel of push notifications.
 @param channel The channel to subscribe to. The channel name must start with
 a letter and contain only letters, numbers, dashes, and underscores.
 @param error Pointer to an NSError that will be set if necessary.
 @return whether the subscribe succeeded.
 */
+ (BOOL)subscribeToChannel:(NSString *)channel error:(NSError **)error;

/*!
 Asynchronously subscribes the device to a channel of push notifications.
 @param channel The channel to subscribe to. The channel name must start with
 a letter and contain only letters, numbers, dashes, and underscores.
 */
+ (void)subscribeToChannelInBackground:(NSString *)channel;

/*!
 Asynchronously subscribes the device to a channel of push notifications and calls the given block.
 @param channel The channel to subscribe to. The channel name must start with
 a letter and contain only letters, numbers, dashes, and underscores.
 @param block The block to execute. The block should have the following argument signature: (BOOL succeeded, NSError *error) 
 */
+ (void)subscribeToChannelInBackground:(NSString *)channel
                                 block:(LCBooleanResultBlock)block;

/*!
 Unsubscribes the device to a channel of push notifications.
 @param channel The channel to unsubscribe from.
 @param error Pointer to an NSError that will be set if necessary.
 @return whether the unsubscribe succeeded.
 */
+ (BOOL)unsubscribeFromChannel:(NSString *)channel error:(NSError **)error;

/*!
 Asynchronously unsubscribes the device from a channel of push notifications.
 @param channel The channel to unsubscribe from.
 */
+ (void)unsubscribeFromChannelInBackground:(NSString *)channel;


/*!
 Asynchronously unsubscribes the device from a channel of push notifications and calls the given block.
 @param channel The channel to unsubscribe from.
 @param block The block to execute. The block should have the following argument signature: (BOOL succeeded, NSError *error) 
 */
+ (void)unsubscribeFromChannelInBackground:(NSString *)channel
                                     block:(LCBooleanResultBlock)block;

@end

NS_ASSUME_NONNULL_END
