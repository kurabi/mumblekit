/* Copyright (C) 2009-2010 Mikkel Krautz <mikkel@krautz.dk>

   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions
   are met:

   - Redistributions of source code must retain the above copyright notice,
     this list of conditions and the following disclaimer.
   - Redistributions in binary form must reproduce the above copyright notice,
     this list of conditions and the following disclaimer in the documentation
     and/or other materials provided with the distribution.
   - Neither the name of the Mumble Developers nor the names of its
     contributors may be used to endorse or promote products derived from this
     software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR
   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
   EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
   PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
   PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
   LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
   NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#import <MumbleKit/MKServerModelObject.h>

typedef enum {
	MKTalkStatePassive = 0,
	MKTalkStateTalking,
	MKTalkStateWhispering,
	MKTalkStateShouting,
} MKTalkState;

@class MKChannel;

@interface MKUser : MKServerModelObject {
	@protected
		BOOL muteState;
		BOOL deafState;
		BOOL suppressState;
		BOOL localMuteState;
		BOOL selfMuteState;
		BOOL selfDeafState;
		MKTalkState _talkState;
		NSUInteger userSession;
		NSString *userName;
		NSUInteger depth;
		MKChannel *channel;
}

- (void) dealloc;

#pragma mark -

- (void) setSession:(NSUInteger)session;
- (NSUInteger) session;

- (void) setUserName:(NSString *)name;
- (NSString *) userName;

- (void) setTalkState:(MKTalkState)val;
- (MKTalkState) talkState;

- (void) setMute:(BOOL)flag;
- (BOOL) muted;

- (void) setDeaf:(BOOL)flag;
- (BOOL) deafened;

- (void) setSuppress:(BOOL)flag;
- (BOOL) suppressed;

- (void) setLocalMute:(BOOL)flag;
- (BOOL) localMuted;

- (void) setSelfMute:(BOOL)flag;
- (BOOL) selfMuted;

- (void) setSelfDeaf:(BOOL)flag;
- (BOOL) selfDeafened;

- (void) setChannel:(MKChannel *)chan;
- (MKChannel *) channel;

@end