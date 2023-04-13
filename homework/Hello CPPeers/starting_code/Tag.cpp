#include "Tag.h"
#include <iostream>
#include <stdexcept>
#include <string>

using std::string, std::vector;

Tag::Tag(string tagName) : tagName(tagName), tagPosts() {
  // throw std::invalid_argument for
  // if the length is less than 2
  if (tagName.length() < 2) {
    throw std::invalid_argument("Tag length must be at least 2");
  }
  // if the first letter is not '#'
  if (tagName[0] != '#') {
    throw std::invalid_argument("Tag must start with '#'");
  }
  // if the second letter is not a-z
  if (!isalpha(tagName[1])) {
    throw std::invalid_argument("Tag must have a second letter be alpha");
  }
  // if the tagName has an uppercase letter
  if (lower(tagName) != tagName) {
    throw std::invalid_argument("Tag cannot contain an uppercase letter");
  }
  // there is one or more consecutive punctuations at the end ('!', ',', '.',
  // '?')
  unsigned long indx = tagName.find_last_of("!,.?");
  if (indx == tagName.length() - 1) {
    throw std::invalid_argument("Tag cannot end in punctuation");
  }
}

string Tag::getTagName() { return tagName; }

vector<Post *> &Tag::getTagPosts() { return tagPosts; }

void Tag::addTagPost(Post *post) {
  // if post is nullptr
  if (post == nullptr) {
    throw std::invalid_argument("post cannot be nullptr");
  }
  tagPosts.push_back(post);
}
