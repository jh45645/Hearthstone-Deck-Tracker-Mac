//
//  CardModel.h
//  Hearthstone-Deck-Tracker
//
//  Created by jeswang on 15/1/11.
//  Copyright (c) 2015年 rainy. All rights reserved.
//

#import <Realm/Realm.h>

@interface CardFilter : NSObject
@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSString *label;
@property (nonatomic, strong) NSDictionary *dict;

@property (nonatomic, strong) NSString *selectedKey;

- (RLMResults *)filterdResult:(RLMResults *)input;
+ (CardFilter *)filterWithName:(NSString *)name label:(NSString *)label dict:(NSDictionary *)dict;

@end

@interface StringObject : RLMObject
@property NSString *value;

+ (StringObject *)stringForValue:(NSString *)value;

@end
RLM_ARRAY_TYPE(StringObject)

@interface CardModel : RLMObject {
}

@property long cost;
@property long health;
@property NSString *flavor;
@property bool collectible;
@property NSString *howToGet;
@property NSString *artist;
@property NSString *cardId;
@property RLMArray<StringObject> *mechanics;
@property NSString *playerClass;
@property NSString *rarity;
@property NSString *localizedName;
@property NSString *name;
@property NSString *text;
@property NSString *cardType;
@property NSString *faction;
@property NSString *lang;
@property NSString *race;

@property NSInteger count;
@property int inHandCount;
@property bool isStolen;
@property bool justDrawn;
@property bool wasDiscarded;

- (NSString*)englishName;

+ (NSDictionary *)JsonMapping;

+ (CardModel *)cardById:(NSString*)cardId ofCountry:(NSString*)country;
+ (CardModel *)cardByEnglishName:(NSString*)name ofCountry:(NSString*)country;

+ (NSArray *)actualCards;
+ (NSArray *)cardWithFilters:(NSArray *)filters;

+ (void)sortCards:(NSArray*)cards;


@end

// This protocol enables typed collections. i.e.:
// RLMArray<CardModel>
RLM_ARRAY_TYPE(CardModel)
