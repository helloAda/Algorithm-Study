//
//  main.swift
//  Algorithm-Swift
//
//  Created by 黄铭达 on 2018/8/23.
//  Copyright © 2018年 黄铭达. All rights reserved.
//

import Foundation

// 字符串翻转
var reverseStr = String("i am a student.".reversed())
var strArray = reverseStr.components(separatedBy: " ")
var result = ""
for str in strArray {
    result.append("\(String(str.reversed())) ")
}
print(result)
