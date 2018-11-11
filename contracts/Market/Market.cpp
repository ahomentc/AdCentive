#include "Market.hpp"
#include <eosiolib/asset.hpp>
#include <stdio.h>

namespace AdCentive {

    // void Market::ad_clicked(account_name user, account_name website, uint64_t adId) {
    //     marketAdIndex ads(_self, _self);

    //     auto iterator = ads.find(adId);
    //     eosio_assert(iterator != ads.end(), "The ad is not found");

    //     auto ad = ads.get(adId);

    //     asset productPrice = asset(product.price, string_to_symbol(4, "OAS"));

    //     action(vector<permission_level>(), N(anorak), N(transfer), make_tuple(buyer, _self, productPrice, string(""))).send();

    //     action(vector<permission_level>(), N(market), N(additem), make_tuple(buyer, 
    //         product.product_id,
    //         product.name,
    //         product.power,
    //         product.health,
    //         product.ability,
    //         product.level_up
    //     )).send();

    //     update(buyer, product.product_id, -1);
    // }    

    void Market::addad(account_name account, account_name user_belong_to, market_ad newAd)
    {
        require_auth(account);

        marketAdIndex ads(_self, _self);

        auto iterator = ads.find(newAd.ad_id);
        eosio_assert(iterator == ads.end(), "Ad for this ID already exists");

        ads.emplace(account, [&](auto& ad) {
            ad.ad_id = newAd.ad_id;
            ad.user_belong_to = user_belong_to;
            ad.name = newAd.name;
            ad.redirect_link = newAd.redirect_link;
            ad.link_to_image = newAd.link_to_image;
            ad.num_to_display = 0;
        });
    }

    void Market::removead(account_name account, uint64_t ad_id)
    {
        require_auth(account);

        marketAdIndex ads(_self, _self);

        auto iterator = ads.find(ad_id);
        eosio_assert(iterator != ads.end(), "Product not found");

        ads.erase(iterator); 
    }

    Market::market_ad Market::requestad(account_name account)
    {
        marketAdIndex ads(_self, _self);

        // get size of ads
        int size = std::distance(ads.begin(),ads.end());

        // get random index in ads
        srand (time(NULL));
        int index = rand() % size;

        auto iter = ads.begin() + index;
        market_ad ad = *iter;
        return ad;
    }

}





