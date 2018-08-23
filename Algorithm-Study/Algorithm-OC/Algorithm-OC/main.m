//
//  main.m
//  Algorithm-OC
//
//  Created by 黄铭达 on 2018/8/23.
//  Copyright © 2018年 黄铭达. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NSString+DSCategory.h"


int main(int argc, const char * argv[]) {
    @autoreleasepool {
        NSString *str = @"i am a student";
        NSLog(@"%@",[str ds_stringByReversed]);
    }
    return 0;
}

