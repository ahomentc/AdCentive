#include "Users.hpp"
#include <eosiolib/asset.hpp>

namespace AdCentive
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

    void Users::updateclicks(account_name account){
        require_auth(account);

        userIndex users(_self, _self);

        auto iterator = users.find(account);
        eosio_assert(iterator != users.end(), "Address for account not found");

        users.modify(iterator, account, [&](auto &user) {
            user.adclicks += 1;
        });
    }

    void Users::createad(account_name account, ad new_ad, uint64_t amount)
    {
        require_auth(account);

        adIndex ads(_self, _self);

        auto iterator = ads.find(new_ad.ad_id);
        eosio_assert(iterator == ads.end(), "Ad for this ID already exists");

        action(vector<permission_level>(), N(usr), N(transfer), make_tuple(account, _self, amount, string(""))).send();

        ads.emplace(account, [&](auto& ad) {
            ad.ad_id = new_ad.ad_id;
            ad.redirect_link = new_ad.redirect_link;
            ad.link_to_image = new_ad.link_to_image;
            ad.num_to_display = (int)(amount * .5);  // token to amoun to display is 1 to 10. 2 token per 1 display
        });

        action(vector<permission_level>(), N(market), N(addad), make_tuple(account, 
            new_ad.ad_id,
            new_ad.redirect_link,
            new_ad.link_to_image,
            (int)(amount * .5)
        )).send();

    }

    // void Users::fundad(account_name account, ad ad_to_fund, uint64_t amount)
    // {
    //     // **** TO BE DONE *****
    // }

}