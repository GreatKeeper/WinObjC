/* Copyright (c) 2006-2007 Christopher J. W. Lloyd

Copyright (c) 2015 Microsoft Corporation. All rights reserved.

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the
following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

#ifndef _NSPREDICATE_H_
#define _NSPREDICATE_H_

#import <Foundation/NSObject.h>
#import <Foundation/NSSet.h>

@class NSArray, NSDictionary;

FOUNDATION_EXPORT_CLASS
@interface NSPredicate : NSObject <NSSecureCoding, NSCopying>

+ (NSPredicate*)predicateWithFormat:(NSString*)format, ...;
+ (NSPredicate*)predicateWithFormat:(NSString*)predicateFormat argumentArray:(NSArray*)arguments;
+ (NSPredicate*)predicateWithFormat:(NSString*)format arguments:(va_list)argList;
+ (NSPredicate*)predicateWithValue:(BOOL)value;
+ (NSPredicate*)predicateWithBlock:(BOOL (^)(id evaluatedObject, NSDictionary* bindings))block;

- (BOOL)evaluateWithObject:(id)object;
- (BOOL)evaluateWithObject:(id)object substitutionVariables:(NSDictionary*)variables;
- (instancetype)predicateWithSubstitutionVariables:(NSDictionary*)variables;
- (void)allowEvaluation;

@property (readonly, copy) NSString* predicateFormat;

@end

#endif /* _NSPREDICATE_H_ */