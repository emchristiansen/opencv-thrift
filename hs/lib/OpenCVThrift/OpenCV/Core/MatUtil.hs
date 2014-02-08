module OpenCVThrift.OpenCV.Core.MatUtil where

import Thrift.Protocol
import Thrift.Transport
{-import qualified Thrift.Protocol.Binary-}

{-import Thrift-}
{-import Thrift.Protocol-}
{-import Thrift.Protocol.Binary-}
{-import Thrift.Transport-}
{-import Thrift.Transport.Handle-}
{-import Thrift.Server-}
{-import GHC.IO.Handle.Types-}

{-import Internal.Util-}

import OpenCVThrift.OpenCV.Core

import qualified MatUtil_Client

data Client p t = (Protocol p, Transport t) => Client { value :: (p t, p t) }

class (Protocol p, Transport t) => ToClient a p t | a -> p t where
  toClient :: a -> Client p t

instance (Protocol p, Transport t) => ToClient (Client p t) p t where
  toClient = id  

pack :: ToClient a p t => a -> CVType -> MatUnpacked -> IO Mat
pack client = MatUtil_Client.pack $ value $ toClient client

{-class Bar a where-}

{-class Bar a => Foo a-}

{-class Thrift.Protocol.Protocol a => Protocol a-}
{-class Thrift.Protocol.Protocol a => MyProtocol a-}

{-class -}
  {-( Thrift.Protocol.Protocol p-}
  {-, Thrift.Transport.Transport t) => Client c p t | c -> p t where-}
    {-cast :: c -> (p t, p t)-}

{-pack :: Client c p t => c -> CVType -> MatUnpacked -> IO Mat-}
{-pack client = MatUtil_Client.pack $ cast client-}


{-pack :: a -> CVType -> MatUnpacked -> IO Mat-}
{-pack :: forall a. (BinaryProtocol a, Grr a) => a -> CVType -> MatUnpacked -> IO Mat-}
{-pack :: Thrift.Protocol.Binary.BinaryProtocol a => (a, a) -> CVType -> MatUnpacked -> IO Mat-}
{-pack :: Protocol a => (a, a) -> CVType -> MatUnpacked -> IO Mat-}
{-pack protocol = MatUtil_Client.pack protocol-}
{-pack protocol = MatUtil_Client.pack $ cast protocol-}

{-class Bar a where-}
  {-bar :: a -> String-}

{-class Foo a where-}
  {-foo :: Bar a => a -> Int-}

{-grr :: Protocol a => String-}
{-grr = undefined-}

{-data RefinedProtocol a = Thrift.Protocol.Protocol a => RefinedProtocol a-}
{-data RefinedProtocol a = Foo a => RefinedProtocol a-}

{-data MatUtilClient = MatUtilClient Client-}

{-class MatUtil a where-}
  {-pack :: (RefinedProtocol a) -> CVType -> MatUnpacked -> IO Mat -}
  {-pack (RefinedProtocol protocol) = MatUtil_Client.pack protocol-}
