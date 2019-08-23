//
//  ViewController.swift
//  SwiftDemo
//
//  Created by Dai Dongpeng on 2019/4/2.
//  Copyright © 2019 momo. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        RFLogInfo(format: "%@", #function);
        self.creatButton()
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        Rifle.updateCurrentPage("RootViewController")
    }

    func creatButton() {
        let titles = ["Test Crash", "自定义异常"];
        for i in 1...titles.count {
            let t =  titles[i - 1]
            let b = self.buttonWithType(type: i, des: t)
            b.frame = CGRect(x: 100, y: 60 * i + 100, width: 100, height: 50)
            b.backgroundColor = UIColor.blue
            b.sizeToFit()
            self.view.addSubview(b)
        }
    }
    
    func buttonWithType(type: Int, des: String) -> UIButton {
        let b = UIButton.init(type: .custom)
        b.setTitle(des, for: UIControl.State.normal)
        b.setTitleColor(UIColor.white, for: UIControl.State.normal)
        b.addTarget(self, action: #selector(buttonAction), for: UIControl.Event.touchUpInside)
        b.tag = type
        return b
    }
    
    @objc func buttonAction(b: UIButton) {
        if 1 == b.tag {
            let arr = [""]
            print(arr[2])
        } else if 2 == b.tag {
            Rifle.reportException(withCategory: RifleExceptionType.cocoa, name: "ex-name", reason: "ex-reason", callStack: nil, extraInfo: nil)
        }
    }
    
    @objc func customExceptionButtonAction() {
        
    }

}


/*
 - (void)createButton {
 NSArray *titles = @[@"Test Crash"];
 for (int i = 1; i <= titles.count; i++) {
 NSString *t = titles[i - 1];
 UIButton *b = [self buttonWithType:i des:t];
 b.frame = CGRectMake(100, 60 * i + 100, 100, 50);
 b.backgroundColor = [UIColor blueColor];
 [b sizeToFit];
 [self.view addSubview:b];
 }
 }
 
 - (UIButton *)buttonWithType:(int)type des:(NSString *)des {
 UIButton *b = [UIButton buttonWithType:UIButtonTypeCustom];
 [b setTitle:des forState:UIControlStateNormal];
 [b addTarget:self action:@selector(buttonAction:) forControlEvents:UIControlEventTouchUpInside];
 b.tag = type;
 return b;
 }
 
 - (void)buttonAction:(UIButton *)b {
 
 BOOL onMain = YES;
 NSInteger t  = b.tag;
 dispatch_block_t block = ^{
 if (t ==  1) {
 RFLogInfo(@" %s will crash",__func__);
 __unused id obj = @[@1][2];
 }
 };
 
 if (onMain) {
 block();
 } else {
 dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
 block();
 });
 }
 
 }
 
 */
