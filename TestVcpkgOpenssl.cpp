// TestVcpkgOpenssl.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <array>
#include <iostream>

#include <openssl/evp.h>

int main()
{
    size_t outLen{0};
    const auto SHA256HashLength{32};
    std::array<unsigned char, SHA256HashLength> messageDigest{};

    const std::string input{
        // ReSharper disable once StringLiteralTypo
        R"(
            Lorem ipsum dolor sit amet, consectetur adipiscing elit. Phasellus scelerisque turpis eu leo molestie, tincidunt pulvinar urna ultricies. Phasellus volutpat ultricies massa, sed ullamcorper augue mattis ac. Nam felis nisi, feugiat ullamcorper tellus in, condimentum ultricies sem. Mauris venenatis nisl ut placerat lobortis. Donec pretium congue tortor vitae rhoncus. Orci varius natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Aliquam ut purus eu ex ultrices tempus.
            Nam sodales ultricies luctus. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Ut volutpat convallis neque, at venenatis ipsum ullamcorper ut. Quisque tempus lorem vel tortor finibus, non dapibus est mattis. Sed venenatis ut lorem vitae maximus. Suspendisse potenti. Curabitur ornare magna vel lorem mollis, et pulvinar ipsum auctor. Curabitur vel urna ligula. Sed viverra urna metus, ut pretium justo iaculis vitae.
            Etiam tincidunt ultrices justo nec aliquet. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia curae; Suspendisse dignissim mi vitae turpis convallis porttitor. In laoreet metus vitae turpis gravida, vel suscipit elit facilisis. Fusce aliquam vel sapien nec porta. Donec convallis efficitur malesuada. Pellentesque eu justo vulputate justo viverra varius. Ut finibus eget ipsum ut facilisis. Curabitur in tristique eros. Nullam vitae augue id est accumsan lacinia. Praesent libero massa, laoreet a interdum et, bibendum non felis. Duis mauris nulla, accumsan quis ex id, pharetra sollicitudin quam. Nulla facilisi. Donec semper eros a dolor vulputate, eu vehicula elit sollicitudin. Duis porta quis est at maximus. Fusce dui ligula, malesuada nec arcu sit amet, facilisis imperdiet ante.
            Vivamus velit dui, egestas sed scelerisque quis, tincidunt eu nulla. Integer leo lorem, tempus sed bibendum ac, viverra vel metus. Praesent et egestas dolor, viverra dapibus metus. Ut consequat orci ante, ut faucibus sem mollis non. Proin pulvinar pretium justo non consectetur. Fusce ut ultrices dui, vitae consectetur elit. Morbi ornare sed velit in luctus. Aliquam commodo maximus eros sit amet sollicitudin. Nunc vulputate odio et vestibulum tempor. Nam fringilla arcu est, sed semper arcu tristique nec. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec varius libero a velit posuere cursus. Donec volutpat maximus leo, sed egestas quam tincidunt non.
            Nullam rhoncus massa vel venenatis faucibus. Mauris tristique dapibus tempus. Integer ligula sapien, blandit sit amet volutpat et, tempus vulputate tellus. Sed et porttitor velit. Cras porta ullamcorper diam vitae maximus. Maecenas accumsan ut sem in mattis. Nunc venenatis tellus justo, et venenatis odio vestibulum ac. Phasellus sagittis velit vel scelerisque lobortis. Sed sed ligula elit. Morbi et orci nisi. Nam efficitur aliquet dui, nec sollicitudin neque efficitur sit amet. Etiam et tellus laoreet, molestie urna eu, suscipit arcu. Morbi dictum felis libero, ut dapibus dolor tincidunt quis.SHA256_HASH_LENGTH
        )"
    };
    auto*  ctx{EVP_MD_CTX_new()};
    EVP_DigestInit(ctx, EVP_sha256());
    EVP_DigestUpdate(ctx, input.c_str(), input.length());
    EVP_DigestFinal_ex(ctx, messageDigest.data(), &outLen);
    EVP_MD_CTX_free(ctx);

    std::cout << "0x";
    for (const auto& c : messageDigest)
    {
        std::cout << std::hex << static_cast<int>(c);
        
    }
    std::cout << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
