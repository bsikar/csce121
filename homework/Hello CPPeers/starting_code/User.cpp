#include "User.h"
#include <stdexcept>
#include <string>

using std::string, std::vector;

User::User(string userName) : userName(userName), userPosts() {
  // throw std::invalid_argument
  // if userName is empty
  if (userName == "") {
    throw std::invalid_argument("user name cannot be empty");
  }
  // if userName doesnt start with a letter a-z
  if (!isalpha(userName[0])) {
    throw std::invalid_argument("user name cannot start with a letter");
  }
  // if userName contains an uppercase letter
  if (userName != lower(userName)) {
    throw std::invalid_argument("user name cannot contain an uppercase letter");
  }
}

string User::getUserName() { return userName; }

vector<Post *> &User::getUserPosts() { return userPosts; }

void User::addUserPost(Post *post) {
  // if post is nullptr
  if (post == nullptr) {
    throw std::invalid_argument("post canont be nullptr");
  }
  userPosts.push_back(post);
}
