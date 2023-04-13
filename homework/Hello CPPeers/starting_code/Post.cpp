#include "Post.h"
#include <cctype>
#include <iostream>
#include <stdexcept>
#include <string>

using std::string, std::vector;

std::string lower(std::string s) {
  // make a string lowercase
  for (unsigned int i = 0; i < s.length(); i++) {
    s[i] = std::tolower(s[i]);
  }
  return s;
}

Post::Post(unsigned int postId, string userName, string postText)
    : postId(postId), userName(userName), postText(postText) {
  if (postId == 0 || userName == "" || postText == "") {
    throw std::invalid_argument("post constructor: invalid parameter values");
  }
}

unsigned int Post::getPostId() { return postId; }

string Post::getPostUser() { return userName; }

string Post::getPostText() { return postText; }

vector<string> Post::findTags() {
  // Returns a vector containing unique candidate tags extracted from postText
  // - Tags are words within postText that begin with a '#'
  // - Tags are not case sensitive
  // - Remove punctuations at the end of each tag
  vector<string> tags;

  string tmpPostText = postText;
  // find the start `#`
  unsigned long indx = tmpPostText.find("#");
  while (indx != string::npos) {
    // take a substr
    string tag = tmpPostText.substr(indx);
    tmpPostText = tmpPostText.substr(indx + 1);
    // find the end of the tag ` ` or `\n` (if its at the end)
    indx = tag.find_first_of(" \n");
    // if is the very last thing in the string
    if (indx != string::npos) {
      // take the tag
      tag = tag.substr(0, indx);
      tmpPostText = tmpPostText.substr(indx);
    }
    // search for punctuation
    indx = tag.find_last_of("!,.?");
    while (indx != string::npos) {
      // verify its the last one
      if (indx != tag.length() - 1) {
        break;
      }
      tag.pop_back();
      indx = tag.find_last_of("!,.?");
    }
    bool good = true;
    for (string s : tags) {
      if (lower(s) == lower(tag)) {
        good = false;
      }
    }
    if (good) {
      tags.push_back(lower(tag));
    }

    indx = tmpPostText.find("#");
  }

  return tags;
}
