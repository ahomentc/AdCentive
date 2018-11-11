#include "Market.hpp"
#include <eosiolib/asset.hpp>

namespace AdCentive {

    /*  when add is clicked:
    reward the user and the website
    subtract 1 from the ad's num to display (not doing now). */
    
    // void Market::ad_clicked(account_name user, account_name website, uint64_t adId) {
    //     marketAdIndex ads(_self, _self);

    //     auto iterator = ads.find(adId);
    //     eosio_assert(iterator != ads.end(), "The ad is not found");

    //     auto ad = ads.get(adId);

    //     action(vector<permission_level>(), N(anorak), N(transfer), make_tuple(buyer, _self, productPrice, string(""))).send();

    //     action(vector<permission_level>(), N(market), N(additem), make_tuple(buyer, 
    //         product.product_id,
    //         product.name,
    //         product.power,
    //         product.health,
    //         product.ability,
    //         product.level_up
    //     )).send();

    //  }    

    void Market::addad(account_name account, market_ad newAd)
    {
        require_auth(account);

        marketAdIndex ads(_self, _self);

        auto iterator = ads.find(newAd.ad_id);
        eosio_assert(iterator == ads.end(), "Ad for this ID already exists");

        ads.emplace(account, [&](auto& ad) {
            ad.ad_id = newAd.ad_id;
            ad.redirect_link = newAd.redirect_link;
            ad.link_to_image = newAd.link_to_image;
            ad.num_to_display = 0;
            ad.user_belong_to = account;
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

    void Market::requestad(account_name account)
    {
        marketAdIndex ads(_self, _self);

        // get size of ads
        int size = std::distance(ads.begin(),ads.end());
       
        // std::time_t now = std::time(0);
        // boost::random::mt19937 gen{static_cast<std::uint32_t>(now)};
        // boost::random::uniform_int_distribution<> dist{0, size-1};

        // int index = dis(gen);
        int index = 0;

        // auto iter = ads.begin() + index;
        auto iter = ads.begin();
        
        // goes through ads till there is one that has non-zero num to display
        while( true )
        {
            market_ad ad = *iter;
            if(ad.num_to_display < 1)
            {
                iter = std::next(iter, 1);
            }
            
        }

        if(iter != ads.end())
        {
            market_ad ad = *iter;

            vector <string> returnAd; 
            returnAd.push_back(std::to_string(ad.ad_id));
            returnAd.push_back(ad.redirect_link);
            returnAd.push_back(ad.link_to_image); 
        }

    }

}





