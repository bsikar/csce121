#include "Network.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

using std::string, std::vector;

Network::Network() : users({}), posts({}), tags({}) {}

void Network::loadFromFile(string fileName) {
  // if the file couldnt be opened throw std::invalid_argument
  std::ifstream file(fileName);
  if (!file.is_open()) {
    throw std::invalid_argument("file could not be opened");
  }

  // read the file line by line
  string line;
  while (std::getline(file, line)) {
    // the file should only have 'User' or 'Post' as the first word
    unsigned long indx = line.find(" ");
    if (indx == string::npos) {
      throw std::runtime_error("invalid syntax");
    }

    std::stringstream ss(line);
    string command;
    ss >> command;

    // if the command is not valid then throw
    if (command == "User") {
      string user;
      if (!(ss >> user)) {
        throw std::runtime_error("invalid user syntax");
      }
      try {
        addUser(user);
      } catch (const std::exception &e) {
        throw std::runtime_error(e.what());
      }
    } else if (command == "Post") {
      unsigned int id;
      string name;
      string post;
      // get all except the post
      if (!(ss >> id >> name)) {
        throw std::runtime_error("invalid post syntax");
      }
      // get the post, it should be the rest of the line
      if (!std::getline(ss, post)) {
        throw std::runtime_error("invalid post syntax");
      }
      // remove the space at the beginning
      post = post.substr(1);
      try {
        addPost(id, name, post);
      } catch (const std::exception &e) {
        throw std::runtime_error(e.what());
      }
    } else {
      throw std::runtime_error("invalid syntax");
    }
  }
}

bool find(vector<User *> users, string name) {
  for (unsigned int i = 0; i < users.size(); i++) {
    string userName = users[i]->getUserName();
    // user names are case insensitive
    if (lower(userName) == lower(name)) {
      return true;
    }
  }
  return false;
}

bool find(vector<Post *> posts, int id) {
  for (unsigned int i = 0; i < posts.size(); i++) {
    int postId = posts[i]->getPostId();
    if (postId == id) {
      return true;
    }
  }
  return false;
}

bool find(vector<Tag *> tags, string tag) {
  for (unsigned int i = 0; i < tags.size(); i++) {
    string tagName = tags[i]->getTagName();
    if (tagName == tag) {
      return true;
    }
  }
  return false;
}

void Network::addUser(string userName) {
  // if a user with the same name exists throw invalid_argument
  if (find(users, userName)) {
    throw std::invalid_argument("user with the same name already exists");
  }

  // create and add user
  User *user = new User(userName);
  users.push_back(user);

  std::cout << "Added User " << userName << std::endl;
}

void Network::addPost(unsigned int postId, string userName, string postText) {
  // if a post with this id already exists throw std::invalid_argument
  if (find(posts, postId)) {
    throw std::invalid_argument("post with this id already exists");
  }
  // if no user with the name exists throw std::invalid_argument
  if (!find(users, userName)) {
    throw std::invalid_argument("no user with this name exists");
  }
  // create and add post
  Post *post = new Post(postId, userName, postText);
  posts.push_back(post);

  // get the tags
  vector<string> tags = post->findTags();
  for (unsigned int i = 0; i < tags.size(); i++) {
    string tag = tags[i];
    // if the tag doesnt exist then create it
    if (!find(this->tags, tag)) {
      try {
        Tag *newTag = new Tag(tag);
        this->tags.push_back(newTag);
      } catch (...) {
      }
    }
    // add the post to the tag
    for (unsigned int j = 0; j < this->tags.size(); j++) {
      if (this->tags[j]->getTagName() == tag) {
        this->tags[j]->addTagPost(post);
      }
    }
  }

  // add the user's posts
  for (unsigned int i = 0; i < users.size(); i++) {
    if (users[i]->getUserName() == userName) {
      users[i]->addUserPost(post);
    }
  }

  std::cout << "Added Post " << postId << " by " << userName << std::endl;
}

vector<Post *> Network::getPostsByUser(string userName) {
  // if the user is empty or not found throw invalid_argument
  if (userName == "") {
    throw std::invalid_argument("user is empty");
  }
  if (!find(users, userName)) {
    throw std::invalid_argument("user is not in network");
  }

  vector<Post *> userPosts;
  for (unsigned int i = 0; i < posts.size(); i++) {
    if (posts[i]->getPostUser() == userName) {
      userPosts.push_back(posts[i]);
    }
  }
  return userPosts;
}

vector<Post *> Network::getPostsWithTag(string tagName) {
  // if the tag is empty or not found throw invalid_argument
  if (tagName == "") {
    throw std::invalid_argument("tag is empty");
  }
  if (!find(tags, tagName)) {
    for (unsigned int i = 0; i < tags.size(); i++) {
      std::cout << tags[i] << std::endl;
    }
    std::cout << tags.size() << std::endl;

    throw std::invalid_argument("tag " + tagName + " is not in network");
  }

  vector<Post *> tagPosts;
  for (unsigned int i = 0; i < posts.size(); i++) {
    vector<string> tags = posts[i]->findTags();
    for (unsigned int j = 0; j < tags.size(); j++) {
      if (tags[j] == tagName) {
        tagPosts.push_back(posts[i]);
      }
    }
  }
  return tagPosts;
}

vector<string> Network::getMostPopularHashtag() {
  vector<string> mostPopular;
  int max = 0;
  for (unsigned int i = 0; i < tags.size(); i++) {
    int tagCount = tags[i]->getTagPosts().size();
    if (tagCount > max) {
      max = tagCount;
      mostPopular.clear();
      mostPopular.push_back(tags[i]->getTagName());
    } else if (tagCount == max) {
      mostPopular.push_back(tags[i]->getTagName());
    }
  }

  return mostPopular;
}

Network::~Network() {
  for (unsigned int i = 0; i < users.size(); ++i) {
    delete users.at(i);
  }

  for (unsigned int i = 0; i < tags.size(); ++i) {
    delete tags.at(i);
  }

  for (unsigned int i = 0; i < posts.size(); ++i) {
    delete posts.at(i);
  }
}
