#ifndef _USER_H
#define _USER_H

#include "Post.h"
#include <string>
#include <vector>

class User {
private:
  std::string userName;
  std::vector<Post *> userPosts;

public:
  User(std::string userName);
  std::string getUserName();
  std::vector<Post *> &getUserPosts();
  void addUserPost(Post *post);
};

#endif
