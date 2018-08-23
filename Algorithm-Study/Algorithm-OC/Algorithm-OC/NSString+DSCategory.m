//
//  NSString+DSCategory.m
//  Algorithm-OC
//
//  Created by 黄铭达 on 2018/8/23.
//  Copyright © 2018年 黄铭达. All rights reserved.
//

#import "NSString+DSCategory.h"

@implementation NSString (DSCategory)

- (NSString *)ds_stringByReversed {
    NSArray *strArray = [self componentsSeparatedByString:@" "];
    NSUInteger length = strArray.count;
    NSMutableString *result = [NSMutableString string];
    [strArray enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        [result appendString:strArray[length - 1 - idx]];
        [result appendString:@" "];
    }];
    return result;
}
@end
