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

    func creatButton() {
        let b = UIButton.init(frame: CGRect(x: 100, y: 100, width: 100, height: 60));
        b.addTarget(self, action: #selector(buttonAction), for: .touchUpInside)
        b.setTitle("Test Crash", for: .normal)
        b.setTitleColor(UIColor.blue, for: .normal)
        self.view.addSubview(b)
    }
    
    @objc func buttonAction() {
        let arr = [""]
        print(arr[2])
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
