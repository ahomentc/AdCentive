#include "Users.hpp"
#include <eosiolib/asset.hpp>

namespace DegreeProof
{
    void Users::adduser(account_name account, string& name, string& username)
    {
        require_auth(account);

        userIndex users(_self, _self);

        auto iterator = users.find(account);
        eosio_assert(iterator == users.end(), "Address for account already exists");

        users.emplace(account, [&](auto &user) 
        {
            user.account_name = account;
            user.name = name;
            user.username = username;
        });
    }

    void Users::getuser(const account_name account) 
    {
        userIndex users(_self, _self);

        auto iterator = users.find(account);
        eosio_assert(iterator != users.end(), "Address for account not found");

        auto currentUser = users.get(account);
        print("Username: ", currentUser.username.c_str());
        print("Name: ", currentUser.name.c_str());
    }

    // user views an add... so update the user's adviews count
    void Users::updateclicks(account_name account){
        require_auth(account);

        userIndex users(_self, _self);

        auto iterator = users.find(account);
        eosio_assert(iterator != users.end(), "Address for account not found");

        users.modify(iterator, account, [&](auto &user) {
            user.adclicks += 1;
        });
    }

}