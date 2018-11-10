#include "Users.hpp"
#include <eosiolib/asset.hpp>

namespace DegreeProof
{
    void Users::adduser(account_name account, string& name, string& username)
    {
        /**
        * We require that only the owner of an account can use this action
        * or somebody with the account authorization
        */
        require_auth(account);

        /**
        * We access the "user" table as creating an object of type "userIndex"
        * As parameters we pass code & scope - _self from the parent contract
        */
        userIndex users(_self, _self);

        /**
        * We must verify that the account doesn't exist yet
        * If the account is not found the iterator variable should be users.end()
        */
        auto iterator = users.find(account);
        eosio_assert(iterator == users.end(), "Address for account already exists");

        /**
        * We add the new user in the table
        * The first argument is the payer of the storage which will store the data
        */
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

        /**
        * The "get" function returns a constant reference to the object
        * containing the specified secondary key
        */
        auto currentUser = users.get(account);
        print("Username: ", currentUser.username.c_str());
        print("Name: ", currentUser.name.c_str());

        if (currentUser.certificatesRecieved.size() > 0) 
        {
            print(" Certficates: ");

            for (uint32_t i = 0; i < currentUser.certificatesRecieved.size(); i++) 
            {
                certificate currentCertificate = currentUser.certificatesRecieved.at(i);
                print(currentCertificate.name.c_str(), " == ");
            }
        } else 
        {
            print(" No certificates recieved ");
        }
    }

}