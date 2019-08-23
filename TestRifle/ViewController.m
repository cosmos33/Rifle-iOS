//
//  ViewController.m
//  TestRifle
//
//  Created by Dai Dongpeng on 2019/3/28.
//  Copyright © 2019 momo. All rights reserved.
//

#import "ViewController.h"
#import <Rifle/Rifle.h>

@interface ViewController ()
@property (nonatomic, strong) id obj;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    RFLogInfo(@" %s ",__func__);
    [self createButton];
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    [Rifle updateCurrentPage:@"RootViewController"];
}

- (void)createButton {
    NSArray *titles = @[@"Test Crash",  @"自定义异常"];
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
        }  else if (t == 2) {
            [Rifle reportExceptionWithCategory:RifleExceptionType_Cocoa name:@"ex-name" reason:@"ex-reason" callStack:@[] extraInfo:nil];
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
@end
