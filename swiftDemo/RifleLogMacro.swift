//
//  RifleLogMacro.swift
//  SwiftDemo
//
//  Created by Dai Dongpeng on 2019/4/2.
//  Copyright © 2019 momo. All rights reserved.
//

import Foundation

public func RFLogDebug(format: String, _ args: CVarArg...){
    RFLogV(.debug, format, getVaList(args));
}

public func RFLogInfo(format: String, _ args: CVarArg...){
    RFLogV(.info, format, getVaList(args));
}

public func RFLogWarn(format: String, _ args: CVarArg...){
    RFLogV(.warn, format, getVaList(args));
}

public func RFLogError(format: String, _ args: CVarArg...){
    RFLogV(.error, format, getVaList(args));
}
