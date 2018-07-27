//
//  OPDataRequest.h
//  OPNetAdapter
//
//  Created by sunboshi on 2018/7/5.
//  Copyright © 2018年 sunobshi.tech. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OPDataResponse.h"
#import <AFNetworking/AFNetworking.h>


@interface OPDataRequest : NSObject

/**
 *  Request domain.
 */
@property (nonatomic, copy) NSString *domain;

/**
 *  Request path
 */
@property (nonatomic, copy) NSString *path;

/**
 *  Request params
 */
@property (nonatomic, strong) NSDictionary *params;

/**
 *  Request timeout
 */
@property (nonatomic, assign) NSTimeInterval timeout;

+ (instancetype)reqeust;

- (NSDictionary *)parametersMap;
- (NSDictionary *)buildParameters;
- (NSDictionary *)headerVaules;

- (NSSet *)acceptableContentTypes;

- (void)prepareForRequest;
- (void)readyForRequest;

- (nullable NSURLSessionDataTask *)getWithSuccess:(void (^)(OPDataResponse *responseObject))success
                failure:(void (^)(NSError *error))failure;

- (nullable NSURLSessionDataTask *)postWithSuccess:(void (^)(OPDataResponse * responseObject))success
                failure:(void (^)(NSError *error))failure;

- (nullable NSURLSessionDataTask *)putWithSuccess:(void (^)(OPDataResponse * responseObject))success
                failure:(void (^)(NSError *error))failure;

- (nullable NSURLSessionDataTask *)deleteWithSuccess:(void (^)(OPDataResponse * responseObject))success
                failure:(void (^)(NSError *error))failure;


- (OPDataResponse *)getResponseParser:(id)response;
- (OPDataResponse *)postResponseParser:(id)response;
- (OPDataResponse *)putResponseParser:(id)response;
- (OPDataResponse *)deleteResponseParser:(id)response;

@end
