#import <Availability.h>
#import <UIKit/UIKit.h>

#define EDSTAR_IOS    0
#define EDSTAR_IOS    1

enum {
    EDStarRatingDisplayFull=0,
    EDStarRatingDisplayHalf,
    EDStarRatingDisplayAccurate
};
typedef NSUInteger EDStarRatingDisplayMode;
typedef void(^EDStarRatingReturnBlock)(float rating);
@protocol EDStarRatingProtocol;

#define EDControl   UIControl
typedef UIColor     EDColor;
typedef UIImage     EDImage;

@interface EDStarRating : EDControl

@property (nonatomic,strong) EDImage *backgroundImage;
@property (nonatomic,strong) EDImage *starHighlightedImage;
@property (nonatomic,strong) EDImage *starImage;
@property (nonatomic) NSInteger maxRating;
@property (nonatomic) float rating;
@property (nonatomic) CGFloat horizontalMargin;
@property (nonatomic) BOOL editable;
@property (nonatomic) EDStarRatingDisplayMode displayMode;
@property (nonatomic) float halfStarThreshold;
@property (nonatomic,weak) id<EDStarRatingProtocol> delegate;
@property (nonatomic,copy) EDStarRatingReturnBlock returnBlock;
@end


@protocol EDStarRatingProtocol <NSObject>

@optional
-(void)starsSelectionChanged:(EDStarRating*)control rating:(float)rating;

@end

