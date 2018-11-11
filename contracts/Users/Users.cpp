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

    void Users::updateclicks(account_name account){
        require_auth(account);

        userIndex users(_self, _self);

        auto iterator = users.find(account);
        eosio_assert(iterator != users.end(), "Address for account not found");

        users.modify(iterator, account, [&](auto &user) {
            user.adclicks += 1;
        });
    }

    void Users::create_ad(account_name account, ad new_ad, uint64_t amount)
    {
        require_auth(account);

        adIndex ads(_self, _self);

        auto iterator = ads.find(new_ad.ad_id);
        eosio_assert(iterator == ads.end(), "Ad for this ID already exists");

        ads.emplace(account, [&](auto& ad) {
            ad.ad_id = new_ad.ad_id;
            ad.redirect_link = new_ad.redirect_link;
            ad.link_to_image = new_ad.link_to_image;
            ad.num_to_display = 0;
        });


        // **** TO BE DONE:  ****

        // action(vector<permission_level>(), N(anorak), N(transfer), make_tuple(buyer, _self, productPrice, string(""))).send();

        // action(vector<permission_level>(), N(market), N(additem), make_tuple(buyer, 
        //     product.product_id,
        //     product.name,
        //     product.power,
        //     product.health,
        //     product.ability,
        //     product.level_up
        // )).send();

    }

    void Users::fund_ad(account_name account, ad ad_to_fund, uint64_t amount)
    {
        // **** TO BE DONE *****
    }

}